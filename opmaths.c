#include "monty.h"

/**
 * addOpera - adds the top two elements together
 * @stack: pointer to the head node pointer of stack
 * @line_fig: the line number
 * Return: Nothing.
 */
void addOpera(stack_t **stack, unsigned int line_fig)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_fig);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * subOpera - subtracts the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @line_fig: the line number
 * Return: Nothing.
 */
void subOpera(stack_t **stack, unsigned int line_fig)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_fig);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * divOpera - divides the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @line_fig: the line number
 * Return: Nothing.
 */
void divOpera(stack_t **stack, unsigned int line_fig)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_fig);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_fig);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * mulOpera - multiplies the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @line_fig: the line number
 * Return: Nothing.
 */
void mulOpera(stack_t **stack, unsigned int line_fig)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_fig);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

/**
 * modOpera - multiplies the top two elements and stores it in second element
 * @stack: pointer to the head node pointer of stack
 * @line_fig: the line number
 * Return: Nothing.
 */
void modOpera(stack_t **stack, unsigned int line_fig)
{
	stack_t *temp;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_fig);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_fig);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(temp);
}

