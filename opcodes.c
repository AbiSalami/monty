#include "monty.h"

/**
  * free_stack - function to free the stack
  * @stack: Stack to be freed
  */

void free_stack(stack_t **stack)
{
	stack_t *curr;

	while (*stack)
	{
		curr = *stack;
		*stack = (*stack)->next;
		free(curr);
	}
}

/**
  * pushIt - Function to add items to the top of stack
  * @stack: Stack to be added
  * @line_fig: Line number in the monty file
  * @thing: Value to be added
  */

void pushIt(stack_t **stack, unsigned int line_fig, int thing)
{
	int mode = 0;
	stack_t *curr;
	stack_t *new_node = malloc(sizeof(stack_t));

	(void)line_fig;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new_node);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new_node->n = thing;
	new_node->prev = NULL;
	if (mode == 0)
	{
		new_node->next = *stack;

		if (*stack)
			(*stack)->prev = new_node;
		*stack = new_node;
	}
	else
	{
		curr = *stack;
		if (curr)
		{
			while (curr->next)
				curr = curr->next;
			curr->next = new_node;
			new_node->next = NULL;
			new_node->prev = curr;
		}
		else
		{
			*stack = new_node;
			new_node->next = NULL;
		}
	}
}

/**
  * pallIt - Function to print the stack items
  * @line_fig: Line number of the file
  * @stack: The current stack in question
  */

void pallIt(stack_t **stack, unsigned int line_fig)
{
	stack_t *curr = *stack;

	(void)line_fig;

	if (*stack == NULL)
		return;

	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

/**
  * pintIt - Prints the value at the top of the stack
  * @stack: the pointer to the stack items
  * @line_fig: line number of the monty file
  */

void pintIt(stack_t **stack, unsigned int line_fig)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_fig);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	while (temp)
	{
		if (temp->prev == NULL)
			break;
		temp = temp->prev;
	}

	printf("%d\n", temp->n);
}

/**
  * swapIt - Function to swap two elements of the stack
  * @stack: Stack to be swapped
  * @line_fig: Line number of the file
  */

void swapIt(stack_t **stack, unsigned int line_fig)
{
	int n1, n2;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_fig);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	n1 = (*stack)->n;
	n2 = (*stack)->next->n;

	(*stack)->n = n2;
	(*stack)->next->n = n1;
}
