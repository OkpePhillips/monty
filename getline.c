#include "monty.h"

/**
 * main - the entry point of the program
 * @argc: this is the arguments count
 * @argv: the argument variables
 *
 * Return: On success 0, else 1
 */

int main(int argc, char *argv[])
{
	char *input_file;
	FILE *file;
	char line[1024];
	unsigned int line_number;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, /"Usage: %s input_file\n", argv[0]);
		return (1);
	}
	input_file = argv[1];
	file = fopen(input_file, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Can't open file %s\n", input_file);
		return (EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(line, sizeof(line), file))
	{
		tokenize(line, line_number, &stack);
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
