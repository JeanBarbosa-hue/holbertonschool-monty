#include "monty.h"

/**
 * main - Entry Point
 * @argc: argument count
 * @argv: argument list
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fileDescriptor, isPush = 0;
	unsigned int lineNumber = 1;
	ssize_t bytesRead;
	char *fileBuffer, *token;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fileDescriptor = open(argv[1], O_RDONLY);
	if (fileDescriptor == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	fileBuffer = malloc(sizeof(char) * 10000);
	if (!fileBuffer)
		return (0);

	bytesRead = read(fileDescriptor, fileBuffer, 10000);
	if (bytesRead == -1)
	{
		free(fileBuffer);
		close(fileDescriptor);
		exit(EXIT_FAILURE);
	}

	token = strtok(fileBuffer, "\n\t\a\r ;:");
	while (token != NULL)
	{
		if (isPush == 1)
		{
			push(&stack, lineNumber, token);
			isPush = 0;
			token = strtok(NULL, "\n\t\a\r ;:");
			lineNumber++;
			continue;
		}
		else if (strcmp(token, "push") == 0)
		{
			isPush = 1;
			token = strtok(NULL, "\n\t\a\r ;:");
			continue;
		}
		else
		{
			if (getOpFunc(token) != 0)
			{
				getOpFunc(token)(&stack, lineNumber);
			}
			else
			{
				freeDList(&stack);
				printf("L%d: unknown instruction %s\n", lineNumber, token);
				exit(EXIT_FAILURE);
			}
		}
		lineNumber++;
		token = strtok(NULL, "\n\t\a\r ;:");
	}

	freeDList(&stack);
	free(fileBuffer);
	close(fileDescriptor);
	return (0);
}
