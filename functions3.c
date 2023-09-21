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