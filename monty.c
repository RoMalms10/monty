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
	char *buf = NULL;
	size_t n = 0;
	FILE *fp;
	vars_t temp = {NULL, NULL, 0};

	vars = &temp;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	for (; getline(&buf, &n, fp) > 0; vars->line_number++)
	{
		vars->tokened = malloc(sizeof(char *) * 2);
		if (vars->tokened == NULL)
			printf("Error: malloc failed\n");
		tokenize(buf);
		/*pass to find function*/
		/*pass to execute function*/
		free_token();
	}
/*	printf("Argument 1: %s\n", vars->tokened[0]); */
/*	printf("Argument 2: %s\n", vars->tokened[1]); */
/*	printf("Line number: %d\n", vars->line_number); */
	fclose(fp);
	return (0);
}
