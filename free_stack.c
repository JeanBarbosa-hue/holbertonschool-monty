#include "monty.h"

/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: Pointer to the stack.
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

