#include "monty.h"
/**
 * add - adds the top two elements of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head != NULL)
	{
		vars->head->next->n = vars->head->n + vars->head->next->n;
		vars->head = vars->head->next;
		free(vars->head->prev);
		vars->head->prev = NULL;

	}
	else
	{
		exit_function(8);
	}
}

/**
 * sub - subtracts the top number form the second number of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head != NULL)
	{
		vars->head->next->n = vars->head->next->n - vars->head->n;
		vars->head = vars->head->next;
		free(vars->head->prev);
		vars->head->prev = NULL;

	}
	else
	{
		exit_function(9);
	}
}
/**
 * divf - divides the top number from the second nubmer of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void divf(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	if (vars->head->n == 0)
		exit_function(13);
	if (vars->head != NULL)
	{
		vars->head->next->n = vars->head->next->n / vars->head->n;
		vars->head = vars->head->next;
		free(vars->head->prev);
		vars->head->prev = NULL;

	}
	else
	{
		exit_function(10);
	}
}
/**
 * mul - multiplies the top two elements of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head != NULL)
	{
		vars->head->next->n = vars->head->n * vars->head->next->n;
		vars->head = vars->head->next;
		free(vars->head->prev);
		vars->head->prev = NULL;

	}
	else
	{
		exit_function(11);
	}
}
/**
 * mod - mods the top number by the second number of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void mod(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head->n == 0)
		exit_function(13);
	if (vars->head != NULL)
	{
		vars->head->next->n = vars->head->next->n % vars->head->n;
		vars->head = vars->head->next;
		free(vars->head->prev);
		vars->head->prev = NULL;

	}
	else
	{
		exit_function(12);
	}
}