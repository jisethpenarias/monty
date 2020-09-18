#include "monty.h"

/**
 * st_opcode - structure that has the function that is implemented.
 * @str: opcode name.
 * @nl: line number.
 * Return: void.
 */

void (*st_opcode(char **str, unsigned int nl)) (stack_t **stack, unsigned int)
{
	int i = 0;
	instruction_t instruct_opcode[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{"swap", _swap},
		{"add", _add},
		{NULL, NULL}
	};
	(void) nl;
	
	while (instruct_opcode[i].opcode)
	{
		if (strcmp(str[0], instruct_opcode[i].opcode) == 0)
		{
			return (instruct_opcode[i].f);
		}
		i++;
	}
	free(str);
	return (NULL);
}
