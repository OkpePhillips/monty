#ifndef _MONTY_
#define _MONTY_

/* Standard Library */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/* Data structures */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Functions declaration */
void tokenize(char *line, unsigned int line_number, stack_t **stack);
void trimLeadingTrailingWhitespaces(char *line);
void pall(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void removeExtraSpaces(char *line);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void handle_opcode(char *token, stack_t **stack, unsigned int line_number);
void remove_extra_spaces(char *str);
void free_stack(stack_t **stack);

#endif
