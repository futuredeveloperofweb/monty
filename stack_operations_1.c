#include "monty.h"


/**
 * push - push a node to stack.
 * @new: a pointer to the new node.
 * @line_n: number of the line
 */
void push(stack_t **new, unsigned int line_n)
{
	stack_t *tm;

	(void)line_n;
	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tm = head;
	head = *new;
	head->next = tm;
	tm->prev = head;
}

/**
 * pall - print the value of the nodes in the stack
 * @stack: a pointer to stack.
 * @line_n: line number
 */
void pall(stack_t **stack, unsigned int line_n)
{
	stack_t *tm;

	(void) line_n;
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
 * pop - remove the head node of the stack
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}

	tm = *stack;
	*stack = tm->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tm);
}
/**
 * pint - print the head node of stack
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void pint(stack_t **stack, unsigned int line_n)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
