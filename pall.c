#include "monty.h"

/**
 *
 *
 *
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *current = *stack; 

	/* Traverse the stack and print its elements */
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
