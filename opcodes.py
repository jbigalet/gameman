import json

import pystache
from bs4 import BeautifulSoup

with open('Gameboy_LR35902_OPCODES.html') as f:
    html = BeautifulSoup(f, 'html.parser')

opcodes = []
prefix_cb_opcodes = []
for table, ops in zip(
        html.find_all('table')[:2],
        [opcodes, prefix_cb_opcodes]
):

    for irow, row in enumerate(table.find_all('tr')[1:]):
        for icol, data in enumerate(row.find_all('td')[1:]):

            sublines = list(data.strings)
            if len(sublines) != 3:
                continue

            opcode = '{:X}{:X}'.format(irow, icol)

            # prefix to load the next set of opcodes
            if opcode == 'CB':
                continue

            read_bytes = []

            command_args = sublines[0].split(' ')
            args = []
            if len(command_args) > 1:
                for arg in command_args[1].split(','):

                    for reg in "ABCDEHL":
                        if arg == '(%s)' % reg:
                            args.append('"($FF00+%s)"' % reg)
                            break

                    else:
                        # wrong doc...
                        if opcode in ['E8', 'F8']:
                            arg = arg.replace('r8', 'd8')

                        if 'd8' in arg:
                            read_bytes.append('u8')
                            args.append('"' + arg.replace('d8', '$" + to_hex_string(b%s) + "' % len(read_bytes)) + '"')
                        elif 'd16' in arg:
                            read_bytes.append('u16')
                            args.append('"' + arg.replace('d16', '$" + to_hex_string(b%s) + "' % len(read_bytes)) + '"')
                        elif 'a8' in arg:
                            read_bytes.append('u8')
                            args.append('"' + arg.replace('a8', '$" + to_hex_string((u16)(65280 + b%s)) + "' % len(read_bytes)) + '"')
                        elif 'a16' in arg:
                            read_bytes.append('u16')
                            args.append('"' + arg.replace('a16', '$" + to_hex_string(b%s) + "' % len(read_bytes)) + '"')
                        elif 'r8' in arg:
                            read_bytes.append('i8')
                            args.append('"' + arg.replace('r8', 'PC" + to_hex_string(b%s, false, true) + "' % len(read_bytes)) + '"')

                        else:
                            args.append('"%s"' % arg)

            size_cycles = sublines[1].split(u'\xa0\xa0')

            cmd_array = ['"%s"' % command_args[0]]
            if args:
                cmd_array.append('" "')
                cmd_array.append(' + "," + '.join(args))
            cmd = ' + '.join(cmd_array)
            cmd = cmd.replace('" + "', '')

            flags = [f for f in sublines[2].split(' ') if f != '-']
            if not flags:
                flags = "no flag"
            else:
                flags = "flags: %s" % ','.join(flags)

            ops.append({
                'opcode': opcode,
                'toread': [{'type': t, 'name': 'b%s' % (i+1)} for i, t in enumerate(read_bytes)],
                'cmd': cmd,
                'timings': size_cycles[1],
                'flags': flags,
            })

with open('disas.template.cpp') as f:
    template = f.read()

rendered = pystache.render(template, {
    'table_kind': [
        {
            'table_suffix': '_prefix',
            'opcodes': prefix_cb_opcodes,
            'prefix_table': True,
        },
        {
            'table_suffix': '',
            'opcodes': opcodes,
            'prefix_table': False,
        },
    ]
})
rendered = rendered.replace('&quot;', '"')
rendered = rendered.replace('&lt;', '<')
rendered = rendered.replace('&gt;', '>')
with open('disas.cpp', 'w') as f:
    f.write(rendered)
