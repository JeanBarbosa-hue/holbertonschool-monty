#include "monty.h"

/**
 * free_stack - Frees the memory allocated for a stack.
 * @stack: Pointer to the stack.
 */

void free_stack(stack_t *stack)
{
	stack_t *temp_stack;

	while (stack)
	{
		temp_stack = stack->next;
		free(stack);
		stack = temp_stack;
	}
}
