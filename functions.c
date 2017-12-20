#include "monty.h"

/**
  * tokenize - tokenizes a line into separate strings
  * @buf: the buffer containing the line of strings
  * Return: nothing, void
  */
void tokenize(char *buf)
{
	char *token;
	/*vars_t vars;*/
	char *tokened[2];
	char *delim;
	int i;

	delim = " '\n'";
	tokened[0] = NULL;
	tokened[1] = NULL;
	token = strtok(buf, delim);
	for (i = 0; token != NULL && i < 2; i++)
	{
		tokened[i] = strdup(token);
		if (tokened[i] == NULL)
		{
			/*if (i == 1)
			 	free(tokened[0])*/
			printf("Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	/*vars->tokened = tokened;*/
}
