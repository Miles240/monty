#include "monty.h"

/**
 * print_top - this function will printthe top node of the stack
 * @stack: is a pointer pointer pointing to another pointer
 * @line_number: is an integer
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
