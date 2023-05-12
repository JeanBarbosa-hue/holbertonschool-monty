#include "monty.h"
/**
 * get_op_func - call appropriate function
 * @tokens: pointer to array of tokens
 * @stack: pointer to a stack
 *
 * Return: nothing
 */
void get_op_func(char **tokens, stack_t **stack)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"add", sub},
		{"add", mul},
		{"add", mod},
		{"add", divh},
		{"nop", nop},
		{NULL, NULL}};
	int idx = 0;

	while (ops[idx].opcode)
	{
		if (tokens[0][0] == '#')
			return;
		if (strcmp(tokens[0], ops[idx].opcode) == 0)
		{
			if (ops[idx].f)
				ops[idx].f(stack, line_number);
			break;
		}
		idx++;
	}

	if (strcmp(tokens[0], "push") == 0)
	{
		is_valid(tokens, stack);
		(*stack)->n = atoi(tokens[1]);
	}
	else if (!(ops[idx].opcode))
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				line_number,
				tokens[0]);
		exit(EXIT_FAILURE);
	}
}
