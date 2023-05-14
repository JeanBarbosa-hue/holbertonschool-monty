#include "monty.h"

/**
 * execute_opcode - Executes the opcode function based on the given opcode.
 * @stack: Double pointer to the head of the stack.
 * @opcode: Opcode string to be executed.
 * @line_number: Line number of the command in the Monty bytecode file.
 */

void execute_opcode(stack_t **stack, char *opcode, unsigned int line_number)
{
	int j;

	/*Define an array of opcodes and their corresponding functions*/
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	/*Iterate through the instructions array*/
	for (j = 0; instructions[j].opcode; j++)
	{
		/*If the opcode matches execute its function*/
		if (strcmp(opcode, instructions[j].opcode) == 0)
		{
			instructions[j].f(stack, line_number);
			return;
		}
	}

	/*If the opcode is not found print an error message and exit*/
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
