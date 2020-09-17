#include "monty.h"

/**
 * get_struct_opcode -
 * @str:
 * 
 * Return: void.
 */

void (*get_struct_opcode(char *str))(stack_tt **stack, unsigned int line_number)
{
    int i = 0;
    instruction_t instruct_opcode[]=
    {
        {"push", _push},
        {"pall", _pall},
        {"nop", _nop},
        {NULL, NULL}
    };
    while (instruct_opcode[i].opcode)
    {
        if (strcmp(str, instruct_opcode[i].opcode) == 0)
        {
            return (instruct_opcode[i].f);
        }
        i++;
    }
    return (NULL);
}
