#include "monty.h"

/**
 * _push -
 * @stack:
 * @line:
 * Return: void.
 */

void _push(stack_tt **top, unsigned int num_line)
{
    stack_tt *auxNode;
    (void) num_line;

    if(stack == NULL)
    {
        (*top)->prev = NULL;
        stack = *top;
    } else {
        auxNode = stack;
        while (auxNode->next != NULL)
        {
            auxNode = auxNode->next;
        }
        auxNode->next = *top;
        (*top)->prev = auxNode;
    }
}

/**
 * _push -
 * @stack:
 * @line:
 * Return: void.
 */

void _nop(stack_tt **stack, unsigned int num_line)
{
    (void) stack;
    (void) num_line;
    /*printf("%u",num_line);*/
}


void _pall(stack_tt **stack, unsigned int num_line)
{
    stack_tt *auxNode;
    (void) num_line;

    auxNode = *stack;
    while (auxNode != NULL)
	{
		printf("%d\n", (auxNode)->n);
		(auxNode) = (auxNode)->prev;
	}
}