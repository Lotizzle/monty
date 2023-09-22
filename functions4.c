#include "monty.h"

/**
 * stack - sets the format of the data to a stack (LIFO)
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void stack(monty_stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    globalvar.mode = "stack";
}

/**
 * queue - sets the format of the data to a queue (FIFO)
 * @stack: pointer to the stack
 * @line_number: line number
 * Return: void
 */
void queue(monty_stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;

    globalvar.mode = "queue";
}
