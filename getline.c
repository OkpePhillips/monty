#include "monty.h"

/**
 *remove_extra_spaces - trims whitespaces in the bytecode
 *@str: the input bytecode
 *
 *Return: Nothing
*/

void remove_extra_spaces(char *str)
{
	int i, j;
	int space_count = 0;
	int in_word = 0;

	i = 0;
	while (isspace(str[i]))
		i++;
	j = 0;
	while (str[i] != '\0')
	{
		if (isspace(str[i]))
		{
			if (in_word)
			{
				str[j++] = ' ';
				in_word = 0;
			}
			space_count++;
		}
		else
		{
			space_count = 0;
			in_word = 1;
			str[j++] = str[i];
		}
		i++;
	}
	if (space_count > 0 && j > 0 && str[j - 1] == ' ')
		j--;
	str[j] = '\0';
}

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
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	input_file = argv[1];
	file = fopen(input_file, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", input_file);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while (fgets(line, sizeof(line), file))
	{
		remove_extra_spaces(line);
		tokenize(line, line_number, &stack);
		line_number++;
	}
	fclose(file);
	return (EXIT_SUCCESS);
}
