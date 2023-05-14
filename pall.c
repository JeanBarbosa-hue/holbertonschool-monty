#include "monty.h"

/**
 * pall - prints all values on the stack, starting from the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file (unused)
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;/*Unused variable, silence the compiler warning*/

	current = *stack;/*Set the current node to the head of the stack*/
	while (current)/*While there is a node in the stack*/
	{
		printf("%d\n", current->n);/*Print the integer value of the current node*/
		current = current->next;/*Move to the next node in the stack*/
	}
}
