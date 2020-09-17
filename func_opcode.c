#include "monty.h"

int number;

/**
 * _push - pushes an element to the stack.
 * @top: Double pointer.
 * @num_line: line number.
 * Return: void.
 */

void _push(stack_tt **top, unsigned int num_line)
{
	stack_tt *auxNode;
	(void)num_line;

	auxNode = malloc(sizeof(stack_tt));
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

void _nop(stack_tt **stack, unsigned int num_line)
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

void _pall(stack_tt **stack, unsigned int num_line)
{
	stack_tt *auxNode;
	(void)num_line;

	auxNode = *stack;
	while (auxNode != NULL)
	{
		fprintf(stdout, "%d\n", (auxNode)->n);
		(auxNode) = (auxNode)->next;
	}
}

/**
 * _free_stack - free the stack
 * @top: Double pointer
 * Return: void.
 */
void _free_stack(stack_tt *top)
{
	stack_tt *temp;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		temp = top;
		top = top->next;
		free(temp);
	}
	free(top);
}
