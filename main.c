#include "monty.h"

/**
 * main - Entry Point
 *
 * Return: 0 on success
 */

int main(int  __attribute__((unused)) ac,  __attribute__((unused)) char **av)
{
	char line[100];
	FILE *file = fopen("input.txt", "r");
	int line_number = 1;

	if (file == NULL)
	{
		printf("File open error!\n");
		return (1);
	}

	while (fgets(line, sizeof(line), file))
	{
		processLine(line, line_number);
		line_number++;
	}

	fclose(file);
	return (0);
}
