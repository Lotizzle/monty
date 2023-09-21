#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

extern int argument_value;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} monty_stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(monty_stack_t **stack, unsigned int line_number);
} instruction_t;

/* functions1 */
void free_stack(monty_stack_t *stack);
void execute(monty_stack_t **stack, char *token, unsigned int line_number);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
/* functions0 */
void push(monty_stack_t **stack, unsigned int line_number);
void pall(monty_stack_t **stack, unsigned int line_number);
void pint(monty_stack_t **stack, unsigned int line_number);
void pop(monty_stack_t **stack, unsigned int line_number);
void swap(monty_stack_t **stack, unsigned int line_number);
/* functions2 */
void add(monty_stack_t **stack, unsigned int line_number);
void sub(monty_stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */
