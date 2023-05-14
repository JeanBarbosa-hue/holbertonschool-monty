#include "monty.h"

/**
 * pall - prints all values on the stack, starting from the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file (unused)
 */

void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *ptrNode;

	ptrNode = *stack; /* Set the current node to the head of the stack */
	
	while (ptrNode)
	{
		printf("%d\n", ptrNode->n); /* Print the integer value of the current node */
		ptrNode = ptrNode->next; /* Move to the next node in the stack */
	}
}
