#include "monty.h"

/**
 * add - function to implement the add instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - function to implement the nop instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * handle_opcode - function to call the appropriate opcode function
 * @token: the bytecode instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void handle_opcode(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t opies[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; opies[i].opcode != NULL; ++i)
	{
		if (strcmp(token, opies[i].opcode) == 0)
		{
			opies[i].f(stack, line_number);
			return;
		}
	}
	printf("L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
