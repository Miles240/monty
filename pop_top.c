#include "monty.h"

/**
 * pop_top - this function adds a node to the stack.
 * @stack: is a pointer pointer pointing to another pointer
 * @line_number: is an integer
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
