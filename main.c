#include "monty.h"

/**
 * main - doubly linked list representation of a stack (or queue)
 * @argc: argument count.
 * @argv: value of each argument.
 * Return: int.
 */

int main(int argc, char **argv)
{
	if (argc != 2)
		error_arg();
	exec_opcode_monty(argv);
	return (0);
}
