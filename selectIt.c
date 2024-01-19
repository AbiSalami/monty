#include "monty.h"

/**
  * choose_opcode - Selects the right opcode
  * @tokens: Token array of elements
  * @stack: The pointer to the stack items
  * @line_number: Line number of the file
  *
  * Return: 0 on success, 1 otherwise
  */

int selectOpcode(char **tokens, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"pall", pallIt},
		{"pint", pintIt},
		{"nop", nopera},
		{"pop", popIt},
		{"swap", swapIt},
		{"sub", subOpera},
		{"add", addOpera},
		{"mul", mulOpera},
		{"div", divOpera},
		{"mod", modOpera},
		{NULL, NULL}
	};

	int i;

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(tokens[0], instructions[i].opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			return (0);
		}
	}

	return (1);
}
