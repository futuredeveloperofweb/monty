#include "monty.h"

/**
 *  push - push a node to stack
 *  @new: a pointer to the node to add
 *  @line_nb: the number of the line
 */
void push(stack_t **new, __attribute__((unused))unsigned int line_nb)
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
	top = *new;
	top->next = tm;
	tm->prev = top;
}

/**
 * pall - printf the nodes in stack
 * @stack: a pointer to the node in the top of the stack
 * @line_nb: the number of the line
 */
void pall(stack_t **stack, unsigned int line_nb)
{
	stack_t *tm;

	(void)line_nb;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	tm = *stack;
	while (tm != NULL)
	{
		printf("%d\n", tm->n);
		tm = tm->next;
	}
}

/**
 * pop - remove a node from stack
 * @stack: a pointer to the node in the top of the stack
 * @line_nb: the number of the line
 */
void pop(stack_t **stack, unsigned int line_nb)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL)
		error_type2(7, line_nb);
	tm = *stack;
	*stack = tm->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tm);
}

/**
 * pint - print the node in the top of the stack
 * @stack: a pointer to the node in the top of the stack
 * @line_nb: the number of the line
 */
void pint(stack_t **stack, unsigned int line_nb)
{
	if (stack == NULL || *stack == NULL)
		error_type2(6, line_nb);
	printf("%d\n", (*stack)->n);
}
