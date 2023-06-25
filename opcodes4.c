#include "monty.h"

/**
 * rotl - function to implement the rotl instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *top;
	stack_t *second_top;

	(void)line_number;
	top = *stack;
	second_top = (*stack)->next;

	if (top == NULL || second_top == NULL)
		return;
	while (second_top->next != NULL)
		second_top = second_top->next;

	second_top->next = top;
	top->prev = second_top;
	top->next->prev = NULL;
	*stack = top->next;
	top->next = NULL;
}

/**
 * rotr - function to implement the rotr instruction
 * @stack: the structure
 * @line_number: the line number in the monty bytecodes
 *
 * Return: nothing
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;
	stack_t *second_last;

	(void)line_number;
	last = *stack;
	second_last = NULL;

	if (last == NULL || last->next == NULL)
		return;

	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
}
