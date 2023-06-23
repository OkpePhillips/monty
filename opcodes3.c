#include "monty.h"

/**
 * divider - function to implement the division instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void divider(stack_t **stack, unsigned int line_number)
{
	int divisor;
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = current->n;
	*stack = current->next;
	(*stack)->prev = NULL;
	(*stack)->n /= divisor;
	free(current);
}

/**
 * mul - function to implement the mul instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void mul(stack_t **stack, unsigned int line_number)
{
	int multiplier;
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	multiplier = current->n;
	*stack = current->next;
	(*stack)->prev = NULL;
	(*stack)->n *= multiplier;
	free(current);
}

/**
 * mod - function to implement the mod instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void mod(stack_t **stack, unsigned int line_number)
{
	int divisor;
	stack_t *current = *stack;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	divisor = current->n;
	*stack = current->next;
	(*stack)->prev = NULL;

	if (divisor == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->n %= divisor;
	free(current);
}

/**
 * pchar - function to implement the pchar instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;

	if (top->n < 0 || top->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (char)(top->n));
	*stack = top->next;

	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(top);
}

/**
 * pstr - function to implement the pstr instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;
	current = *stack;

	while (current != NULL && current->n != 0
			&& current->n >= 0 && current->n <= 127)
	{
		printf("%c", (char)(current->n));
		current = current->next;
	}
	printf("\n");
}
