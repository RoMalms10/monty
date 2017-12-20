#include "monty.h"

/**
  * find_op - searches for opcode in struct
  * Return: Nothing, void
  */
void find_op(void)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	int x;

	for (x = 0; ops[x].opcode != NULL; x++)
	{
		if (strcmp(vars->tokened[0], ops[x].opcode) == 0)
		{
			ops[x].f(NULL, 0);
			break;
		}
	}
	if (ops[x].opcode == NULL)
	{
		printf("L%d: unknown", vars->line_number);
		printf(" instruction %s\n", vars->tokened[0]); 
		free_token();
		exit(EXIT_FAILURE);
	}
}
