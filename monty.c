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
	int n = 0;
	FILE *fp;
	int l_count;
	vars_t temp = {NULL, NULL, 1};

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

	for (l_count = 1; getline(&buf, &n, fp) > 0; l_count++)
	{
		/*vars->line_number = l_count;*/
		tokenize(buf);
		/*pass to find function*/
		/*pass to execute function*/
	}
	return (0);
}
