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
	(*top)->next = aux->next;
	aux->prev = NULL;
	aux->next = *top;
	*top = aux;
}

/**
 * _pint - prints the value at the top of the stack.
 * @top: Double pointer
 * @num_line: line number.
 * Return: void.
 */

void _pint(stack_t **top, unsigned int num_line)
{
	stack_t *aux = *top;

	if (aux)
		fprintf(stdout, "%d\n", aux->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
}
