#include "monty.h"
stack_t *stack = NULL;

/**
 *have_space - this function validates characters other than spacesh.
 *@line: characters to validate.
 * Return: 0
 */

int have_space(char *line)
{
	unsigned int i;

	for (i = 0; i < strlen(line) - 1; i++)
	{
		if (line[i] != ' ')
		{
			return (1);
		}
	}
	return (0);
}

/**
 * build_node - build_node
 * @top: value of each argument.
 * @n: value.
 * Return: void
 */

void build_node(stack_t **top, int n)
{
	*top = (stack_t *)malloc(sizeof(stack_t));
	if (!(*top))
		error_malloc();

	(*top)->n = n;
}

/**
 * exec_opcode_monty - opcode execution.
 * @argv: value of each argument.
 * Return: void
 */

void exec_opcode_monty(char **argv)
{
	FILE *fd;
	char *line = NULL, *eachString[3];
	unsigned int num_line = 1;
	int rd = 0;
	void (*funct)(stack_t **stack, unsigned int num_line);
	stack_t *top = NULL;
	size_t len;

	fd = fopen(argv[1], "r");
	if (!fd)
		error_open(argv);

	while ((rd = getline(&line, &len, fd)) != EOF)
	{
		if (rd >= 1 && have_space(line))
		{
			tokenizer(line, eachString);
			funct = struct_opcode(eachString[0]);
			if (strcmp(eachString[0], "push") == 0)
				build_node(&top, atoi(eachString[1]));
			funct(&top, num_line);
			num_line++;
		}
	}
	fclose(fd);
}
