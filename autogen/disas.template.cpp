{{#table_kind}}
std::string disas{{table_suffix}}(bool with_bytes=true, bool with_timings=true, bool with_flags=true) {
    u8 opcode = read_pc_u8();
    switch(opcode) {
        {{#opcodes}}
        case 0x{{opcode}}:
        {
            {{#toread}}
            {{type}} {{name}} = read_pc_{{type}}();
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

        {{^prefix_table}}
        case 0xCB:
            return disas_prefix(with_bytes, with_timings, with_flags);
        {{/prefix_table}}
    }

    return "Unkown upcode " + to_hex_string(opcode);
}


{{/table_kind}}
