#include "monty.h"

int argument_value = 0;

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack
 * Return: void
 */
void free_stack(monty_stack_t *stack)
{
	monty_stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
 * execute - executes an opcode
 * @stack: pointer to the stack
 * @token: opcode
 * @line_number: line number
 * Return: void
 */
void execute(monty_stack_t **stack, char *token, unsigned int line_number)
{
	int i = 0;
	char *opcode;
	char *argument;

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	opcode = strtok(token, " \n\t");

	if (!opcode || opcode[0] == '#')
		return;

	argument = strtok(NULL, " \n\t");

	if (opcode && strcmp(opcode, "push") == 0)
	{
		if (!argument || !isdigit(argument[0]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		argument_value = atoi(argument);
	}

	while (opcodes[i].opcode != NULL)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}

/**
 * _getline - reads a line from a file
 * @lineptr: pointer to the line
 * @n: number of bytes
 * @stream: pointer to the file
 * Return: number of bytes read
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read;

	read = getline(lineptr, n, stream);
	if (read == -1)
	{
		free(*lineptr);
		exit(EXIT_SUCCESS);
	}
	return (read);
}
