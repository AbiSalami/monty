#include "monty.h"

/**
  * free_close_exit - Does the work of free line, stack and close,exit
  * @line: The particular line
  * @stack: The stack we're working with
  * @file: The file which is being read
  */

void free_close_exit(char *line, stack_t *stack, FILE *file)
{
	free(line);
	free_stack(&stack);
	fclose(file);
	exit(EXIT_FAILURE);
}

/**
  * parseFile - Executes operations on the file
  * @file: The file to be operated on
  */

void parseFile(FILE *file)
{
	size_t plus = 0;
	char *buf = NULL, *value_of_str;
	unsigned int line_fig = 0;
	char **tokens;
	stack_t *stack = NULL;

	while (getline(&buf, &plus, file) != -1)
	{
		line_fig++;
		if (!buf)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free_close_exit(buf, stack, file);
		}
		if (buf[0] == '#')
			continue;
		tokens = tokenize(buf);
		if (tokens == NULL)
			continue;
		if (strcmp(tokens[0], "push") == 0)
		{
			value_of_str = tokens[1];
			if (value_of_str == NULL || !is_valid_integer(value_of_str))
			{
				fflush(stdout);
				fprintf(stderr, "L%d: usage: push integer\n", line_fig);
				free(value_of_str);
				free_close_exit(buf, stack, file);
			}
			pushIt(&stack, line_fig, atoi(value_of_str));
		}
		else if (selectOpcode(tokens, &stack, line_fig) == 1)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_fig, tokens[0]);
			free_close_exit(buf, stack, file);
		}
		free_array(tokens);
	}
	free(buf);
	free_stack(&stack);
}
