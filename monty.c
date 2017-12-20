#include "monty.h"

/**
  * main - Entry Point
  * @argc: Number of arguments
  * @argv: Arguments names
  * Return: 0 on success, exit on failures
  */
vars_t *vars;
int main(int argc, char **argv)
{
	size_t n = 0;
	vars_t temp = {NULL, NULL, NULL, NULL, 1};

	vars = &temp;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	vars->fp = fopen(argv[1], "r");
	if (vars->fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (; getline(&(vars->buf), &n, vars->fp) > 0; vars->line_number++)
	{
		vars->tokened = malloc(sizeof(char *) * 2);
		if (vars->tokened == NULL)
			printf("Error: malloc failed\n");
		tokenize(vars->buf);
		find_op();
		free_token();
	}
	free(vars->buf);
	fclose(vars->fp);
	return (0);
}
