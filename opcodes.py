import json

import pystache
from bs4 import BeautifulSoup

with open('Gameboy_LR35902_OPCODES.html') as f:
    html = BeautifulSoup(f, 'html.parser')

allargs = set()
prototypes = {}
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

            size_cycles = sublines[1].split(u'\xa0\xa0')
            timings = size_cycles[1]

            read_bytes = []

            command_args = sublines[0].split(' ')
            printed_args = []
            exec_args = []  # (type reg8-16|flag|mem|const8-16, realtype u8-16|i8-16..., value)
            other_ops = []
            if len(command_args) > 1:
                for arg in command_args[1].split(','):
                    allargs.add(arg)
                    isconst = False

                    for reg in "ABCDEHL":
                        if arg == '(%s)' % reg:
                            printed_args.append('"($FF00+%s)"' % reg)
                            exec_args.append({
                                'type': 'mem',
                                'realtype': 'u16',
                                'value': "0xff00+reg.%s" % reg
                            })
                            break

                    else:
                        # wrong doc...
                        if opcode in ['E8', 'F8']:
                            arg = arg.replace('r8', 'd8')

                        exec_val = None
                        if 'd8' in arg:
                            read_bytes.append('u8')
                            printed_args.append('"' + arg.replace('d8', '$" + to_hex_string(b%s) + "' % len(read_bytes)) + '"')
                            exec_val = "read<u8>(it)"

                        elif 'd16' in arg:
                            read_bytes.append('u16')
                            printed_args.append('"' + arg.replace('d16', '$" + to_hex_string(b%s) + "' % len(read_bytes)) + '"')
                            exec_val = "read<u16>(it)"

                        elif 'a8' in arg:
                            read_bytes.append('u8')
                            printed_args.append('"' + arg.replace('a8', '$" + to_hex_string((u16)(0xff00 + b%s)) + "' % len(read_bytes)) + '"')
                            exec_val = "0xff00+read<u8>(it)"

                        elif 'a16' in arg:
                            read_bytes.append('u16')
                            printed_args.append('"' + arg.replace('a16', '$" + to_hex_string(b%s) + "' % len(read_bytes)) + '"')
                            exec_val = "read<u16>(it)"

                        elif 'r8' in arg:
                            read_bytes.append('i8')
                            printed_args.append('"' + arg.replace('r8', 'PC" + to_hex_string(b%s, false, true) + "' % len(read_bytes)) + '"')
                            exec_val = "read<i8>(it)"

                        else:
                            printed_args.append('"%s"' % arg)

                            # assume the arg is a const
                            for digit in "0123456789":
                                if digit in arg:
                                    isconst = True
                                    exec_val = '0x%s' % (arg[:-1] if arg.endswith('H') else arg)

                        if arg.startswith("("):
                            if not exec_val:
                                if arg == "(HL-)":
                                    other_ops.append("reg.HL--")
                                    exec_val = "reg.HL"
                                elif arg == "(HL+)":
                                    other_ops.append("reg.HL++")
                                    exec_val = "reg.HL"
                                else:
                                    exec_val = "reg.%s" % arg[1:-1]

                            exec_args.append({
                                'type': 'mem',
                                'realtype': 'u16',
                                'value': exec_val,
                            })

                        elif isconst:
                            exec_args.append({
                                'type': 'const8',
                                'realtype': 'u8',
                                'value': exec_val,
                            })

                        else:  # not const, not mem
                            if exec_val:  # read stuff, not mem => kinda const
                                exec_args.append({
                                    'type': 'const%s' % read_bytes[-1][1:],
                                    'realtype': read_bytes[-1],
                                    'value': exec_val,
                                })

                            # jump + 1st arg + either c, nc, z or nz => flag
                            elif command_args[0].lower() in ['jp', 'jr', 'call', 'ret'] \
                                    and arg.lower() in ['nz', 'z', 'c', 'nc'] \
                                    and len(exec_args) == 0:  # not a jump - reg

                                if arg.startswith('N'):  # inv
                                    val = "!reg.F%s" % arg[1:]
                                else:  # not inv
                                    val = "reg.F%s" % arg

                                exec_args.append({
                                    'type': 'flag',
                                    'realtype': 'bool',
                                    'value': val,
                                })

                            else:  # reg
                                b = 8*len(arg)
                                exec_args.append({
                                    'type': 'reg%s' % b,
                                    'realtype': 'u%s*' % b,
                                    'value': "&reg.%s" % arg
                                })

            raw_flags = ','.join(sublines[2].split(' '))

            func_name = '_'.join([command_args[0]] + [ea['type'] for ea in exec_args])
            call_func = "%s(%s)" % (func_name, ', '.join([ea['value'] for ea in exec_args]))
            if '/' in timings:
                call_func = "bool action_taken = %s" % call_func
                special_timings = "action_taken ? %s : %s" % tuple(timings.split('/'))
                proto_rtype = 'bool'
            else:
                special_timings = timings
                proto_rtype = 'void'

            proto_name = ("%s %s(%s);" \
                          % (proto_rtype,
                             func_name,
                             ','.join([ea['realtype'] for ea in exec_args])))

            if not proto_name in prototypes:
                prototypes[proto_name] = {
                    'usage': [opcode],
                    'flags': raw_flags,
                }
            else:  # check flags & add to usage

                # ignore F1 as it pops to AF, so it does modify the flags as a side effect
                if prototypes[proto_name]['flags'] != raw_flags and opcode != 'F1':
                    print prototypes[proto_name]
                    print opcode + " => " + raw_flags
                    raise RuntimeError('A prototype cant have different set of flags')
                prototypes[proto_name]['usage'].append(opcode)

            call_funcs = [call_func] + other_ops

            cmd_array = ['"%s"' % command_args[0]]
            if printed_args:
                cmd_array.append('" "')
                cmd_array.append(' + "," + '.join(printed_args))
            cmd = ' + '.join(cmd_array)
            cmd = cmd.replace('" + "', '')

            flags = "flags: %s" % raw_flags

            ops.append({
                'opcode': opcode,
                'toread': [{'type': t, 'name': 'b%s' % (i+1)} for i, t in enumerate(read_bytes)],
                'cmd': cmd,
                'timings': timings,
                'special_timings': special_timings,
                'flags': flags,
                'call_funcs': [{'func': f} for f in call_funcs],
            })

for fname in ['disas', 'cpu_dispatcher']:
    with open('%s.template.cpp' % fname) as f:
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
    with open('%s.cpp' % fname, 'w') as f:
        f.write(rendered)

proto_funcs = ["// usage: %s\n// flags: %s\n%s" % (','.join(p['usage']), p['flags'], pfunc)
               for pfunc, p in sorted(prototypes.items(), key=lambda p: p[0].split(' ', 1)[1])]
with open('cpu_prototypes.cpp', 'w') as f:
    f.write('\n\n'.join(proto_funcs))

