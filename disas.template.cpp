{{#table_kind}}
std::string disas{{table_suffix}}(std::vector<i8>::iterator* it, bool with_bytes=true, bool with_timings=true, bool with_flags=true) {
    u8 opcode = read<u8>(it);
    switch(opcode) {
        {{#opcodes}}
        case 0x{{opcode}}:
        {
            {{#toread}}
            {{type}} {{name}} = read<{{type}}>(it);
            {{/toread}}
            std::string str;
            if(with_bytes) {
                str += "[";
                {{#prefix_table}}
                str += "CB ";
                {{/prefix_table}}
                str += "{{opcode}}";
                {{#toread}}
                str += " " + to_hex_string({{name}}, true);  // with spaces
                {{/toread}}
                str += "] ";

                str.insert(str.size(), 12-str.size(), ' ');  // align
            }

            str += {{cmd}};

            if(with_timings) {
                str.insert(str.size(), 40-str.size(), ' ');  // align
                str += " cycles: {{timings}}";
            }

            if(with_flags) {
                str.insert(str.size(), 60-str.size(), ' ');  // align
                str += " {{flags}}";
            }

            return str;
        }
        {{/opcodes}}

        case 0xCB:
            return disas_prefix(it, with_bytes, with_timings, with_flags);
    }

    return "Unkown upcode " + to_hex_string(opcode);
}


{{/table_kind}}
