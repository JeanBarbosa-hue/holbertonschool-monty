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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	/*Check if the correct number of arguments is provided*/
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

	global_variable = malloc(sizeof(global_t));
	if (!global_variable)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	global_variable->argument = NULL;

	/*Read the file line by line*/
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;

		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}

		opcode = strtok(line, " \t");/*Added '\t' to handle tab characters*/
		/*Check if the line is not empty or starts with a comment*/
		if (opcode != NULL && opcode[0] != '#')
		{
		global_variable->argument = strtok(NULL, " \t");

		/*Execute the opcode*/
		execute_opcode(&stack, opcode, line_number);
		}

		free(line);
		line = NULL;
		len = 0;
	}

	/*Close the file and free the memory*/
	fclose(file);
	free(line);
	free(global_variable);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
