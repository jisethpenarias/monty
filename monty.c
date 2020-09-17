#include "monty.h"
stack_tt *stack = NULL;

/**
 * build_node - 
 * @argv: value of each argument.
 * 
 * Return: void
 */

void build_node(stack_tt **top, int n)
{
    *top = (stack_tt *)malloc(sizeof(stack_tt));
    if (!(*top))
        error_malloc();
	
	(*top)->n = n;
}


/**
 * exec_opcode_monty - 
 * @argv: value of each argument.
 * 
 * Return: void
 */

void exec_opcode_monty(char **argv)
{
    FILE *fd;
	char *line = NULL, *eachString[3];
	unsigned int num_line = 1;
	void (*funct)(stack_tt **stack, unsigned int num_line);
    stack_tt *top = NULL;
	size_t len;

    fd = fopen(argv[1], "r");
	if(!fd)
        error_open(argv);
    
    while (getline(&line, &len, fd) != EOF)
	{
		tokenizer(line, eachString);
		funct = get_struct_opcode(eachString[0]);
		if (strcmp(eachString[0], "push") == 0)
			build_node(&top, atoi(eachString[1]));
		funct(&top, num_line);
		num_line++;
	}
    fclose(fd);
	/*
	if (!line)
		free(line);*/
}
