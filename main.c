#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE.
 */
global_t *global_variable = NULL;

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL, *opcode;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	}

	global_variable = malloc(sizeof(global_t));
	if (!global_variable)
	{
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		opcode = strtok(line, " \t");
		if (opcode != NULL && opcode[0] != '#')
		{
			global_variable->argument = strtok(NULL, " \t");
			execute_opcode(&stack, opcode, line_number);
		}

		free(line), line = NULL, len = 0;
	}

	fclose(file), free(line), free(global_variable), free_stack(stack);
	return (EXIT_SUCCESS);
}
