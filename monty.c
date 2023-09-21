#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	monty_stack_t *stack = NULL;
	unsigned int line_number = 0;
	ssize_t read = 0;
	size_t len = 0;
	char *token = NULL;
	FILE *file = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read != -1)
	{
		line_number++;
		read = _getline(&token, &len, file);
		if (read > 0)
			execute(&stack, token, line_number);
		else
			free(token);
	}
	fclose(file);
	free_stack(stack);

	return (0);
}
