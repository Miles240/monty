#include "monty.h"

/**
 * rotr - this function will rotate the last node to the top
 * @stack: is a pointer pointer pointing to another pointer
 * @ln: is an integer
 */
void rotr(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
