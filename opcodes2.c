#include "monty.h"

/**
  * popIt - Pops an object from the top of the stack
  * @stack: The stack under consideration
  * @line_fig: Line number of the monty file
  */

void popIt(stack_t **stack, unsigned int line_fig)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_fig);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	*stack = curr->next;

	if (*stack)
		(*stack)->prev = NULL;


	free(curr);
}


/**
  * nopera - No opcode
  * @stack: Stack in question
  * @line_fig: Line number of the monty file
  */

void nopera(stack_t **stack, unsigned int line_fig)
{
	(void)stack;
	(void)line_fig;
}
