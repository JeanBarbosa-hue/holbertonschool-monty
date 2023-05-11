#include "monty.h"

void push(int value, int line_number)
{
	if (top == STACK_SIZE - 1)
	{
		printf("Error: L%d: Stack overflow!\n", line_number);
		exit(EXIT_FAILURE);
	}
	top++;
	stack[top] = value;
}
