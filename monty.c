#include "monty.h"

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	char *token = NULL;
	int i = 0;

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

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		while (isspace(*line))
			line++;
		
		while (isspace(line[strlen(line) - 1]))
			line[strlen(line) - 1] = '\0';
		
		if (*line == '\0')
			continue;
		
		token = strtok(line, " ");
		while (token != NULL)
		{
			if (strcmp(token, "push") == 0)
				push(&stack, line_number);
			else if (strcmp(token, "pall") == 0)
				pall(&stack, line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
				exit(EXIT_FAILURE);
			}
			token = strtok(NULL, " ");
		}
	}
	fclose(file);
	return (0);
}