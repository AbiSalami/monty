#include "monty.h"

/**
 * main - Entry point for the Monty interpreter
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: Always 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	/* stack_t *stack = NULL; */

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Call your function to parse Monty byte code files */
	parseFile(file);

	fclose(file);
	return (0);
}
