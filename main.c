#include "monty.h"

int main(void)
{
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;  // Initialize line number to 1

    while ((read = getline(&line, &len, stdin)) != -1)
    {
        /* Tokenize the line and process the opcode */
        /* Example: */
        char *opcode = strtok(line, " \t\n");
        if (opcode != NULL)
        {
            if (strcmp(opcode, "push") == 0)
                push(&stack, line_number);
            else if (strcmp(opcode, "pall") == 0)
                pall(&stack, line_number);
            /* Handle other opcodes */
        }
        
        line_number++;  // Increment line number after processing each line
    }

    free(line);
    return 0;
}
