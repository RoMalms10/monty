#include "monty.h"

/**
  * pchar - prints the ASCII character of the value stored in the top of stack
  * @stack: the double pointer to the beginning of the list (NULL)
  * @line_number: the line of the file it's on (always passed 0)
  * Return: nothing, void
  */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;

	if (vars->head->n < 0 || vars->head->n > 127)
		exit_function(15);
	putchar(vars->head->n);
	putchar('\n');
}

/**
  * pstr - prints the ASCII character of the value stored in
  * all of the linked list
  * @stack: the double pointer to the beginning of the list (NULL)
  * @line_number: the line of the file it's on (always passed 0)
  * Return: nothing, void
  */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *traverse;

	(void) stack;
	(void) line_number;
	traverse = vars->head;
	while (traverse != NULL)
	{
		if (traverse->n < 1 || traverse->n > 127)
			break;
		putchar(traverse->n);
		traverse = traverse->next;
	}
	putchar('\n');
}
