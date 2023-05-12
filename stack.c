#include "monty.h"

/**
 * print - prints the top for the stack
 * @stack: pointered to a stack
 * @n: line number that opcode is call at.
 */

void print(stack_t **stack, unsigned int n)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", n);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", (*stack)->n);
}
