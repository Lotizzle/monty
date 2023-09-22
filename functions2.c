#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

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
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

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
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _div - divides the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * mul - multiplies the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}
