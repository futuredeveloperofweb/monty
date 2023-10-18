#include "monty.h"

/**
 * error_type - print the right error message
 * @error_code: the error to print
 */
void error_type(int error_code, ...)
{
	va_list a;
	char *op_c;
	int line_nb;

	va_start(a, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(a, char *));
			break;
		case 3:
			line_nb = va_arg(a, int);
			op_c = va_arg(a, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n",
					line_nb, op_c);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n",
					va_arg(a, int));
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * error_type2 - print the right error message
 * @error_code: the error to print
 */
void error_type2(int error_code, ...)
{
	va_list a;
	char *op_c;
	int line_nb;

	va_start(a, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
					va_arg(a, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
					va_arg(a, int));
			break;
		case 8:
			line_nb = va_arg(a, unsigned int);
			op_c = va_arg(a, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n"
					, line_nb, op_c);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * mk_node - create a node
 * @n: the value of the node
 * Return: a pointer to the node, otherwise return the apropriate error
 */
stack_t *mk_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		error_type(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_node - frees all the nodes
 */
void free_node(void)
{
	stack_t *tm;

	if (top == NULL)
		return;
	while (top != NULL)
	{
		tm = top;
		top = top->next;
		free(tm);
	}
}

/**
 * add_queue - push node to queue
 * @new: the node to push
 * @line_nb: the line nb
 */
void add_queue(stack_t **new, __attribute__((unused))unsigned int line_nb)
{
	stack_t *tm;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (top == NULL)
	{
		top = *new;
		return;
	}
	tm = top;
	while (tm->next != NULL)
		tm = tm->next;
	tm->next = *new;
	(*new)->prev = tm;
}
