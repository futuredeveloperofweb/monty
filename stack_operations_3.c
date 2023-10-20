#include "monty.h"

/**
 * mul - multiplies the top two element of the stack
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void mul(stack_t **stack, unsigned int line_n)
{
	int m;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	m = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = m;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mod - get the rest of the division of the top two element of the stack
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void mod(stack_t **stack, unsigned int line_n)
{
	int r;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	r = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = r;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void pchar(stack_t **stack, unsigned int line_n)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_n);
		exit(EXIT_FAILURE);
		free_node();
	}
	if (isascii((*stack)->n))
	{
		printf("%c\n", (*stack)->n);
		return;
	}
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_n);
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * pstr - prints the string starting at the top of the stack
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void pstr(stack_t **stack, unsigned int line_n)
{
	stack_t *tm = *stack;

	(void) line_n;

	if (stack == NULL || *stack == NULL)
	{
		putchar('\n');
		return;
	}
	while (tm)
	{
		if (tm->n == 0)
			break;
		if (!(isascii(tm->n)))
			break;
		printf("%c", tm->n);
		tm = tm->next;
	}
	putchar('\n');
}
