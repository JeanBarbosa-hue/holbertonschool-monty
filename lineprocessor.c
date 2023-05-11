#include "monty.h"

void processLine(char *line, int line_number)
{
	line[strcspn(line, "\n")] = '\0';

	char opcode[10];
	int arg;

	if (sscanf(line, "%s %d", opcode, &arg) != 2)
	{
		printf("Error: L%d: Invalid instruction format\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (strcmp(opcode, "push") == 0)
	{
		if (arg == 0 && strcmp(line, "push 0") != 0)
		{
			printf("Error: L%d: Usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		push(arg, line_number);
	}

	else if (strcmp(opcode, "pall") == 0)
	{
		pall();
	}

	else
	{
		printf("Error: L%d: Unknown opcode: %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
