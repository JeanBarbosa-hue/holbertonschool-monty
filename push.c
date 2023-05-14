#include "monty.h"

/*
 * push - pushes an element to the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;

	/*No stack or no argument, print an error message and exit*/
	if (!stack || !global_variable->argument)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}


	new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/*Assign the integer value from the argument to the new node*/
	new_node->n = atoi(global_variable->argument);
	new_node->prev = NULL;/*Set the 'prev' pointer of the new node to NULL*/
	/*Set the next pointer of the new node to the curent head of the stack*/
	new_node->next = *stack;

	if (*stack)/*If there's an existing head of the stack*/
		(*stack)->prev = new_node;/*Set its 'prev' pointer to the new node*/

	*stack = new_node;/*Set the head of the stack to the new node*/
}
