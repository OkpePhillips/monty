#include "monty.h"

/**
 * tokenize - function to tokenize and call the appropriate opcode function
 * @line: the input monty bytecode
 * @line_number: the line number on the bytecode file
 * @stack: the appropriate bytecode function
 *
 * Return: Nothing
 */
void tokenize(char *line, unsigned int line_number, stack_t **stack)
{
	int i;
	char *token = strtok(line, " \t\n");

	i = 0;

	if (token == NULL || strncmp(token, "#", 1) == 0)
		return;
	while (token != NULL)
	{
		if (token[strlen(token) - 1] == '$')
		{
			token[strlen(token) - 1] = '\0';
		}
		else if (strlen(token) > 0 && i == 0)
		{
			handle_opcode(token, stack, line_number);
			i++;
		}
		else if (strcmp(token, "push") == 0)
			handle_opcode(token, stack, line_number);

		token = strtok(NULL, " \t\n");
	}
}
