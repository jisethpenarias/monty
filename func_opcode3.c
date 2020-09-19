#include "monty.h"

/**
 * _mul - sub the top 2 elements from the top
 * @top: Double pointer stack.
 * @num_line: line number.
 * Return: void.
 */

void _mul(stack_t **top, unsigned int num_line)
{
	stack_t *aux = *top;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (aux->next)
	{
		aux->next->n *= (*top)->n;
		(*top) = (*top)->next;
		(*top)->prev = NULL;
		free(aux);
	}
	else
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod - sub the top 2 elements from the top
 * @top: Double pointer stack.
 * @num_line: line number.
 * Return: void.
 */

void _mod(stack_t **top, unsigned int num_line)
{
	stack_t *aux = *top;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (aux->next)
	{
		aux->next->n %= (*top)->n;
		(*top) = (*top)->next;
		(*top)->prev = NULL;
		free(aux);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
}
