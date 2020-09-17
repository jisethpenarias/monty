#include "monty.h"

/**
 * st_opcode - structure that has the function that is implemented.
 * @str: opcode name.
 * @nl: line number.
 * Return: void.
 */

void (*st_opcode(char *str, unsigned int nl)) (stack_t **stack, unsigned int)
{
	int i = 0;
	instruction_t instruct_opcode[] = {
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
	error_instruction(str, nl);
	return (NULL);
}
