#include "monty.h"

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
 *validate_number - this function validates characters other than spacesh.
 *@number: string number.
 *@num_line: characters to validate.
 * Return: 0
 */

void validate_number(char *number, unsigned int num_line)
{
	unsigned int i, len;

	len = strlen(number);
	for (i = 0; i < len; i++)
	{
		if (!isdigit(number[i]))
			break;
	}
	if (len != i || strcmp(number, "") == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", num_line);
		exit(EXIT_FAILURE);
	}
}

/**
 * exec_opcode_monty - opcode execution.
 * @argv: value of each argument.
 * Return: void
 */

void exec_opcode_monty(char **argv)
{
	FILE *fd;
	char *line = NULL, *eachString[2], auxToken[1000];
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
		eachString[0] = "";
		eachString[1] = "";
		if (rd >= 1 && have_space(line))
		{
			tokenizer(line, eachString);
			strcpy(auxToken, eachString[0]);
			if (strcmp(auxToken, "") == 0 || strcmp(auxToken, "#") == 0)
			{
				num_line++;
				continue;
			}
			if (strcmp(auxToken, "push") == 0)
			{
				validate_number(eachString[1], num_line);
				number = atoi(eachString[1]);
			}
			funct = st_opcode(eachString[0], num_line);
			funct(&top, num_line);
		}
		num_line++;
	}
	fclose(fd);
	if (line != NULL)
		free(line);
	_free_stack(top);
}
