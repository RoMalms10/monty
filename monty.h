#ifndef MONTY_SEEN
#define MONTY_SEEN

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

 /**
  * struct vars_s - holds all variables to be passed
  * @tokened: tokenized string of our input from file
  * @head: head of our stack
  * @line_number: line number that was just read from file
  * @buf: buffer for the line in the file
  *
  * Description: A struct that we make global to pass variables
  *  for stack, queues, LIFO, FIFO holberton project
  */
 typedef struct vars_s
 {
        char **tokened;
	char *buf;
        struct stack_s *head;
        unsigned int line_number;
 } vars_t;

extern vars_t *vars;
/* Stack functions functions.c */
stack_t *add_stack(void);
void tokenize(char *buf);
void free_token(void);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
/* More stack functions functions_2.c */
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
/* Calculation functions functions_3.c */
void add(stack_t **stack, unsigned int line_number);
void divf(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
/* Function finder op_finder.c */
void find_op(void);
/* Stack function in functions_4.c */
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
#endif
