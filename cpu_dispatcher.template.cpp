{{#table_kind}}
i32 exec_op{{table_suffix}}(std::vector<i8>::iterator* it) {
    u8 opcode = read<u8>(it);
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
            return exec_op_prefix(it);
    }

    std::cout << "Unkown upcode " + to_hex_string(opcode) << std::endl;
    unreachable();
    return 0;
}


{{/table_kind}}
