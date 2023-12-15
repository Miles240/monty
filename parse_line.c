#include "monty.h"

/**
 * parse_line - this function will separate each line into tokens
 * and finds which functio to call
 * @buffer: it is theline from the file
 * @line_number: line number
 * @format: this is the storage format
 * Return: Returns 0 or 1
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);

	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_func(opcode, value, line_number, format);
	return (format);
}
