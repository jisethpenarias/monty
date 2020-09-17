#include "monty.h"

/**
 * error_arg - If the user does not give any file or more than one argument the error is printed
 * @void: void
 * 
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
 * 
 * Return: void
 */

void error_open(char **argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

/**
 * error_instruction - If the file contains an invalid statement, print the error message
 * @instruction: 
 * @line: line in file.
 * Return: void
 */

void error_instruction(char *instruction, unsigned int line)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line, instruction);
	exit(EXIT_FAILURE);
}

/**
 * error_malloc - If the file contains an invalid statement, print the error message
 * 
 * Return: void
 */

void error_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
