#include "monty.h"

/**
 * print_str - this function will print a string.
 * @stack: is a pointer pointer pointing to another pointer
 * @ln: is an integer
 */
void print_str(stack_t **stack, __attribute__((unused)) unsigned int ln)
{
	int ascii;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp != NULL)
	{
		ascii = tmp->n;
		if (ascii <= 0 || ascii > 127)
			break;
		printf("%c", ascii);
		tmp = tmp->next;
	}
	printf("\n");
}
