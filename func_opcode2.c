#include "monty.h"

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
 * _add - add the top 2 elements from the top
 * @top: Double pointer stack.
 * @num_line: line number.
 * Return: void.
 */

void _add(stack_t **top, unsigned int num_line)
{
	stack_t *aux = *top;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (aux->next)
	{
		aux->next->n += (*top)->n;
		(*top) = (*top)->next;
		(*top)->prev = NULL;
		free(aux);
	}
	else
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * _free_stack - free the stack
 * @top: Double pointer
 * Return: void.
 */

void _free_stack(stack_t *top)
{
	stack_t *aux;

	if (top == NULL)
		return;

	while (top != NULL)
	{
		aux = top;
		top = top->next;
		free(aux);
	}
	free(top);
}
