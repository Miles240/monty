#include "monty.h"

#include "monty.h"

/**
 * nop - this function does nothin
 * @stack: is a pointer pointer pointing to another pointer
 * @line_number: is an integer
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap_nodes - this function will swap top two elements of the stack
 * @stack: is a pointer pointer pointing to another pointer
 * @line_number: is an
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
