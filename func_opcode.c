#include "monty.h"

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

	if (stack == NULL)
	{
		(*top)->prev = NULL;
		stack = *top;
	}
	else
	{
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
		printf("%d\n", (auxNode)->n);
		(auxNode) = (auxNode)->prev;
	}
}
