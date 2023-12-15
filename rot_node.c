#include "monty.h"

/**
 * rotl - this function will rotate the first node to the bottom
 * @stack: is a pointer pointer pointing to another pointer
 * @ln: is an integer
 */
void rotl(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
