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
//	char *token[2];
	int i;

	delim = " '\n'";
	token = strtok(buf, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		vars->tokened[i] = strdup(token);
		if (vars->tokened[i] == NULL)
		{
			if (i == 1)
				free_token();
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
//		vars->tokened[i] = tokened[i];
		token = strtok(NULL, delim);
	}
}

/**
  * free_token - Frees malloc'd tokens
  * Return: Nothing, void
  */
void free_token(void)
{
	free(vars->tokened[0]);
	free(vars->tokened[1]);
	free(vars->tokened);
}
