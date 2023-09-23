#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void push(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *new_node, *last;

	(void)line_number;

	new_node = malloc(sizeof(monty_stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = globalvar.argument_value;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (strcmp(globalvar.mode, "stack") == 0)
	{
		new_node->next = *stack;
		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else if (strcmp(globalvar.mode, "queue") == 0)
	{
		if (*stack == NULL)
			*stack = new_node;
		else
		{
			last = *stack;
			while (last->next != NULL)
				last = last->next;
			last->next = new_node;
			new_node->prev = last;
		}
	}
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pall(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *current = (*stack);

	(void)line_number;

	while (current != NULL)
	{
		fprintf(stdout, "%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pint(monty_stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void pop(monty_stack_t **stack, unsigned int line_number)
{
	monty_stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void swap(monty_stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!(*stack) || !((*stack)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
