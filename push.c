#include "monty.h"

/**
 *
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *arg = NULL;
	int value;

	/* Read the argument */
	arg = strtok(NULL, " \t\n");
	
	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Convert the argument to an integer */
	value = atoi(arg);

	/* Create a new stack node */
	stack_t *new_node = malloc(sizeof(stack_t));
	
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	new_node->n = value;
	new_node->prev = NULL;

	/* Add the new node to the stack */
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	new_node->next = *stack;
	*stack = new_node;
}
