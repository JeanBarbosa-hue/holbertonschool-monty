#include "monty.h"

void pall(int i)
{
	for (i = top; i >= 0; i--)
	{
		printf("%d\n", stack[i]);
	}
}
