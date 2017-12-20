#include "monty.h"

/**
  * tokenize - tokenizes a line into separate strings
  * @buf: the buffer containing the line of strings
  * Return: nothing, void
  */
void tokenize(char *buf)
{
	char *token;
	char *delim;
	int i;

	delim = " '\n'";
	token = strtok(buf, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		vars->tokened[i] = strdup(token);
		if (vars->tokened[i] == NULL)
		{
			if (i == 1)
			{
				printf("Is it in strtok?\n"); /*delete*/
				free_token();
			}
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
}

/**
  * free_token - Frees malloc'd tokens
  * Return: Nothing, void
  */
void free_token(void)
{
	if (vars->tokened[0] != NULL)
		free(vars->tokened[0]);
	if (vars->tokened[1] != NULL)
		free(vars->tokened[1]);
	vars->tokened = NULL;
}
/*
void pall(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("Pall\n");
	printf("Pall Line: %d\n", vars->line_number);
}

void push(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("push %d\n", 2);
	printf("push Line: %d\n", vars->line_number);
}*/
