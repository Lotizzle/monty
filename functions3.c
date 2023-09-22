#include "monty.h"

/**
 * mod - computes the rest of the division of the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void mod(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * pchar - prints the char at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pchar(monty_stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n >= 32 && (*stack)->n <= 126)
		fprintf(stdout, "%c\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pstr(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *temp = *stack;

	(void) line_number;

	while (temp)
	{
		if (temp->n <= 0 || temp->n > 127)
			break;
		fprintf(stdout, "%c", temp->n);
		temp = temp->next;
	}
	fprintf(stdout, "\n");
}
