#include "monty.h"

/**
 * err - this function prints error messages according to error code.
 * @error_code: Thse are the error codes
 * (1) => no file or more than one file
 * (2) => file cannot be opened or read
 * (3) => file contains invalid instruction
 * (4) => program is unable to malloc more memory
 * (5) => parameter passed to the instruction is not an int
 * (6) => stack empty for pint
 * (7) => stack empty for pop
 * (8) => stack is too short
 */
void err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 1:
		fprintf(stderr, "USAGE: monty file\n");
		break;
	case 2:
		fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
		break;
	case 3:
		l_num = va_arg(ag, int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
		break;
	case 4:
		fprintf(stderr, "Error: malloc failed\n");
		break;
	case 5:
		fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
		break;
	default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - this function handles errors
 * @error_code: these are the error codes
 * (6) => For when stack it empty for pint
 * (7) => stack it empty for pop.
 * (8) => for stack that is too short for operation.
 * (9) => Division by zero(0)
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
	case 6:
		fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
		break;
	case 7:
		fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
		break;
	case 8:
		l_num = va_arg(ag, unsigned int);
		op = va_arg(ag, char *);
		fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
		break;
	case 9:
		fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
		break;
	default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - this func handles errors(string)
 * @error_code: These are the error codes
 * (10) => for when number inside a node is outside ASCII bounds.
 * (11) => for whenstack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
	case 10:
		fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
		break;
	case 11:
		fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
		break;
	default:
		break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
