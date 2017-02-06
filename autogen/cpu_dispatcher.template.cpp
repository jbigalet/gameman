{{#table_kind}}
i32 exec_op{{table_suffix}}() {
    u8 opcode = read_pc<u8>();
    switch(opcode) {
        {{#opcodes}}
        case 0x{{opcode}}:
        {
            {{#call_funcs}}
            {{{func}}};
            {{/call_funcs}}
            return {{special_timings}};
        }
        {{/opcodes}}

        case 0xCB:
            return exec_op_prefix();
    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
    return 0;
}


{{/table_kind}}
