#include "monty.h"

/**
 * err_type - dispalay the right error messages
 * @err_nb: the nb of the error code
 */
void err_type(int err_nb, ...)
{
	va_list ag;
	char *op_c;
	int l;

	va_start(ag, err_nb);
	switch (err_nb)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l = va_arg(ag, int);
			op_c = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l, op_c);
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
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * err_type2 - dispalay the right error messages
 * @err_nb: the nb of the error code
 */
void err_type2(int err_nb, ...)
{
	va_list ag;
	char *op_c;
	int l;

	va_start(ag, err_nb);
	switch (err_nb)
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
			l = va_arg(ag, unsigned int);
			op_c = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l, op_c);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
