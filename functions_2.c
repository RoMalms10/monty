#include "monty.h"

/**
  * pint - prints the number at the top of the stack
  * @stack: the double pointer to the head (NULL)
  * @line_number: the line we're on (always passed 0)
  * Return: nothing, void
  */
void pint(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head == NULL)
	{
		printf("L%d: can't pint, stack empty\n", vars->line_number);
		free_token();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", vars->head->n);
}

/**
  * pop - deletes the struct on the top of the stack
  * @stack: the double pointer to the head (NULL)
  * @line_number: the line we're on (always passed 0)
  * Return: nothing, void
  */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse;

	(void) stack;
	(void) line_number;

	traverse = vars->head->next;
	if (vars->head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", vars->line_number);
		free_token();
		exit(EXIT_FAILURE);
	}
	if (traverse != NULL)
		traverse->prev = NULL;
	free(vars->head);
	vars->head = traverse;
}

/**
 * swap - swaps the top two numbers of the stack
 * @stack: not used
 * @line_number: not used
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp = 0;

	(void) stack;
	(void) line_number;
	if (vars->head != NULL)
	{
		temp = vars->head->n;
		vars->head->n = vars->head->next->n;
		vars->head->next->n = temp;
	}
	else
	{
		printf("L%d: can't swap, stack too short\n", vars->line_number);
		free_token();
		exit(EXIT_FAILURE);
	}
  
 /**
  * nop - function that does nothing
  * @stack: the double pointer to the head (NULL)
  * @line_number: the line we're on (always passed 0)
  * Return: nothing, void
  */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
