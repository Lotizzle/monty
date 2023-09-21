#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void add(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void sub(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * nop - does nothing
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void nop(monty_stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
