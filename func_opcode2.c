#include "monty.h"

/**
 * _pop - removes the top element of the stack.
 * @top: Double pointer stack.
 * @num_line: line number.
 * Return: void.
 */

void _pop(stack_t **top, unsigned int num_line)
{
	stack_t *aux;

	if (!*top)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (!((*top)->next))
	{
		free(*top);
		*top = NULL;
		return;
	}
	aux = (*top)->next;
	*top = aux;
	aux->prev = ((*top)->prev = NULL);
}
