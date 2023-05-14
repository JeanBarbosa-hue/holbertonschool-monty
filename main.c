#include "monty.h"

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 * Return: EXIT_SUCCESS on success, otherwise EXIT_FAILURE.
 */

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/*Open the Monty bytecode file*/
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	glob = malloc(sizeof(global_t));
	if (!glob)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	glob->argument = NULL;

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (line[read - 1] == '\n')
			line[read - 1] = '\0';

		opcode = strtok(line, " \t");
		/*Check if the line is not empty or starts with a comment*/
		if (opcode != NULL && opcode[0] != '#')
		{
		glob->argument = strtok(NULL, " \t");

		/*Execute the opcode*/
		execute_opcode(&stack, opcode, line_number);
		}

		/*Free the line buffer and reset the length*/
		free(line);
		line = NULL;
		len = 0;
	}

	/*Close the file and free the memory*/
	fclose(file);
	free(line);
	free(glob);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
