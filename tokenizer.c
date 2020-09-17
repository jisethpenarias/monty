#include "monty.h"

/**
 * tokenizer - separate each string from a line within a file
 * @line: line in file.
 * @eachString: save each tokenized string.
 * 
 * Return: void
 */

void tokenizer(char *line, char **eachString)
{
	int i = 0;
	char *token = NULL;
    
	token = strtok(line, "\t\n\r ");
	while (token)
	{
		eachString[i] = token;
		i++;
		token = strtok(NULL, "\t\n\r ");
	}
}
