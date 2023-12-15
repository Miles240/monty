#include "monty.h"

/**
 * print_char - this function prints the Ascii value
 * @stack: is a pointer pointer pointing to another pointer
 * @line_number: is a pointer pointer pointing to another pointer
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int ascii;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	ascii = (*stack)->n;
	if (ascii < 0 || ascii > 127)
		string_err(10, line_number);
	printf("%c\n", ascii);
}
