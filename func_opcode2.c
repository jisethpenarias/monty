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
 * _swap - removes the top element of the stack.
 * @top: Double pointer stack.
 * @num_line: line number.
 * Return: void.
 */

void _swap(stack_t **top, unsigned int num_line)
{
	stack_t *aux = *top;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", num_line);
		exit(EXIT_FAILURE);
	}
	aux = (*top)->next;
	(*top)->prev = aux;
	aux->prev = NULL;
	(*top)->next = aux->next;
	aux->next = *top;
	*top = aux;
}
