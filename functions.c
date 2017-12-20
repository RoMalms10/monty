#include "monty.h"
/**
 * add_stack - add a node at the beggining of a stack_t
 * @head: double pointer to head of list
 * @n: number to add to n member
 * Return: Address of new node or NULL if failed
 */
stack_t *add_stack(stack_t **head, const int n)
{
	stack_t *temp = NULL;

	if (head == NULL)
		return (NULL);
	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
		return (NULL);
	temp->next = (*head == NULL) ? NULL : *head;
	temp->prev = NULL;
	temp->n = n;
	if (*head)
		(*head)->prev = temp;
	*head = temp;
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

/**
 * pall - print all integers in a stack_t list
 * @stack: NULL
 * @line_number: 0
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *head = vars->head;

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
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newnode = NULL;
	int i = 0, f = 0;
	char *temp = vars->tokened[1];

	newnode = add_stack(vars->head, 0);
	if (newnode == NULL)
	{
		printf("Error: malloc failed");
		free_token();
		exit(EXIT_FAILURE);
	}
	if (temp)
	{
		while (temp[i])
		{
			if (isdigit(temp[i]) == 0)
			{
				f = 1;
				break;
			}
			i++;
		}
		if (f = 0)
		{
			newnode->n = atoi(temp);
			return;
		}
	}
	printf("L%d: usage: push integer", vars->line_number);
	free_token();
	exit(EXIT_FAILURE);


}
