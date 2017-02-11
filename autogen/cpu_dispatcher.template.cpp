{{#table_kind}}
void exec_op{{table_suffix}}() {
    u8 opcode = read_pc_u8();
    switch(opcode) {
        {{#opcodes}}
        case 0x{{opcode}}:
        {
            cycle_count_advance({{special_timings}});
            {{#call_funcs}}
            {{{func}}};
            {{/call_funcs}}
            return;
        }
        {{/opcodes}}

        {{^prefix_table}}
        case 0xCB:
            exec_op_prefix();
            return;
        {{/prefix_table}}
    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
}


{{/table_kind}}
