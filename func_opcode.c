#include "monty.h"

int number;

/**
 * _push - pushes an element to the stack.
 * @top: Double pointer.
 * @num_line: line number.
 * Return: void.
 */

void _push(stack_t **top, unsigned int num_line)
{
	stack_t *auxNode;
	(void)num_line;

	auxNode = malloc(sizeof(stack_t));
	if (!auxNode)
		error_malloc();
	auxNode->n = number;
	auxNode->prev = NULL;
	if (*top == NULL)
	{
		auxNode->next = NULL;
		*top = auxNode;
	}
	else
	{
		auxNode->next = *top;
		(*top)->prev = auxNode;
		*top = auxNode;
	}
}

/**
 * _nop - opcode nop doesn’t do anything.
 * @stack: Double pointer
 * @num_line: line number.
 * Return: void.
 */

void _nop(stack_t **stack, unsigned int num_line)
{
	(void)stack;
	(void)num_line;
}

/**
 * _pall - prints all the values on the stack, starting from the top stack.
 * @stack: Double pointer
 * @num_line: line number.
 * Return: void.
 */

void _pall(stack_t **stack, unsigned int num_line)
{
	stack_t *auxNode;
	(void)num_line;

	auxNode = *stack;
	while (auxNode != NULL)
	{
		fprintf(stdout, "%d\n", (auxNode)->n);
		(auxNode) = (auxNode)->next;
	}
}
