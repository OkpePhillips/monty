#include "monty.h"

/**
 * push - function to implement the push instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *token;
	int value;
	int i;
	stack_t *new_node;

	token = strtok(NULL, " \t\n");
	if (token == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = 0;
	if (token[i] == '-')
		i++;
	for (; token[i] != '\0'; i++)
	{
		if (!isdigit(token[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	value = atoi(token);
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * pall - function to implement the pall instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current	= *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - function to implement the pint instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - function to implement the pop instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;

	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - function to implement the swap instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}
