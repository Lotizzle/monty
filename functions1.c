#include "monty.h"

global_t globalvar = {0, "stack"};

/**
 * free_stack - frees a stack
 * @stack: pointer to the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	stack_t *temp;

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
void execute(stack_t **stack, char *token, unsigned int line_number)
{
	int i = 0, flag;
	char *opcode, *argument;
	instruction_t opcodes[] = {
		{"push", push}, {"pint", pint}, {"pop", pop}, {"nop", nop}, {"pstr", pstr},
		{"pall", pall}, {"swap", swap}, {"add", add}, {"div", _div}, {"rotl", rotl},
		{"sub", sub}, {"mul", mul}, {"mod", mod}, {"pchar", pchar}, {"rotr", rotr},
		{"queue", queue}, {"stack", _stack}, {NULL, NULL}
	};

	opcode = strtok(token, " \n\t");
	if (!opcode || opcode[0] == '#')
		return;
	argument = strtok(NULL, " \n\t");
	if (opcode && strcmp(opcode, "push") == 0)
	{
		if (argument)
		{
			for (i = 1; argument[i] != '\0'; i++)
				flag = (!isdigit(argument[i])) ? 1 : 0;
			i = 0;
		}
		if (!argument || flag == 1 || (!isdigit(argument[0]) && argument[0] != '-'))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		globalvar.argument_value = atoi(argument);
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
	const size_t chunk_size = 128;
	char *buffer;
	size_t cur_size = 0, i, total_size = 0;
	int c;

	if (*lineptr == NULL || *n == 0)
	{
		*n = chunk_size;
		*lineptr = malloc(*n);
	}
	if (*lineptr == NULL)
		return (-1);
	buffer = *lineptr;
	while (1)
	{
		c = fgetc(stream);
		if (c == EOF)
		{
			if (total_size == 0 || ferror(stream))
				return (-1);
			break;
		}
		buffer[total_size++] = (char) c;
		if (total_size >= *n)
		{
			cur_size = *n;
			*n += chunk_size;
			*lineptr = malloc(*n);
			if (*lineptr == NULL)
				return (-1);
			for (i = 0; i < cur_size; ++i)
				(*lineptr)[i] = buffer[i];
			free(buffer);
			buffer = *lineptr;
		}
		if (c == '\n')
			break;
	}
	buffer[total_size] = '\0';
	return (total_size);
}


