#include "monty.h"
/**
 * add_stack - add a node at the beggining of a stack_t
 * @h: double pointer to head of list
 * @n: number to add to n member
 * Return: Address of new node or NULL if failed
 */
stack_t *add_stack(void)
{
	stack_t *temp = NULL;
	int n = 0;
	stack_t *head = vars->head;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	temp->next = (head == NULL) ? NULL : head;
	temp->prev = NULL;
	temp->n = n;
	if (head)
		head->prev = temp;
	vars->head = temp;
	return (temp);
}

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

	vars->tokened[0] = NULL;
	vars->tokened[1] = NULL;
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
	if (vars->tokened != NULL)
		free(vars->tokened);
	vars->tokened = NULL;
}

/**
 * pall - print all integers in a stack_t list
 * @stack: NULL
 * @line_number: 0
 * Return: nothing, void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = vars->head;

	(void) stack;
	(void) line_number;
	if (head == NULL)
		return;
	while(head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}

}

/**
 * pall - print all integers in a stack_t list
 * @stack: NULL
 * @line_number: 0
 * Return: nothing, void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int i = 0, f = 0, negative = 0;
	char *temp = vars->tokened[1];

	(void) stack;
	(void) line_number;

	newnode = add_stack();
	if (newnode == NULL)
	{
		printf("Error: malloc failed\n");
		free_token();
		exit(EXIT_FAILURE);
	}
	if (temp != NULL)
	{
		if (temp[0] == '-')
		{
			i++;
			f = 1;
			negative = 1;
		}
		while (temp[i] != '\0')
		{
			if (isdigit(temp[i]) == 0) /*0 if not digit*/
			{
				f = 1;
				break;
			}
			i++;
			f = 0;
		}
		if (f == 0)
		{
			if (negative == 1)
				temp = temp + 1;
			newnode->n = atoi(temp);
			if (negative == 1)
				newnode->n *= -1;
			return;
		}
	}
	/*exit here so don't have to write it twice*/
	printf("L%d: usage: push integer\n", vars->line_number);
	free_token();
	exit(EXIT_FAILURE);
}
