#include "monty.h"

/**
 * error_arg - If the user dosent give any file.
 * @void: void
 * Return: void
 */

void error_arg(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * error_open - if the file cannot be opened, the error message is printed
 * @argv: value of each argument.
 * Return: void
 */

void error_open(char **argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

/**
 * error_instruction - file contains an invalid statement, print error message
 * @opfunct: opcode and its function.
 * @line: line in file.
 * Return: void
 */

void error_instruction(char *opfunct, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, opfunct);
	exit(EXIT_FAILURE);
}

/**
 * error_malloc - if malloc fails, print error message
 * Return: void
 */

void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
