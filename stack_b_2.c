#include "monty.h"

/**
  * pop_b - Pops an object from the top of the stack
  * @stack: The stack under consideration
  * @line_num: Line number of the monty file
  */

void pop_b(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	*stack = curr->next;

	if (*stack)
		(*stack)->prev = NULL;


	free(curr);
}


/**
  * nop_b - No opcode
  * @stack: Stack in question
  * @line_num: Line number of the monty file
  */

void nop_b(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
