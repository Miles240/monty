#include "monty.h"

#include "monty.h"

/**
 * add_to_stack - tis function adds a node to the stack
 * @new_node: it is a pointer to the new node
 * @ln: these are intergers that represents the line number of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}
