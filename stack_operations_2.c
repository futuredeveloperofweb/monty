#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_n)
{
	(void)stack;
	(void)line_n;
}

/**
 * swap - swap the top two elements of the stack.
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_n)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	tm = (*stack)->next;
	(*stack)->next = tm->next;
	if (tm->next != NULL)
		tm->next->prev = *stack;
	tm->next = *stack;
	(*stack)->prev = tm;
	tm->prev = NULL;
	*stack = tm;
}

/**
 * add - add the top two elements of the stack.
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void add(stack_t **stack, unsigned int line_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - substruct the top two elements of the stack.
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void sub(stack_t **stack, unsigned int line_n)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div - devide the toop two elements of the stack
 * @stack: pointer to stack.
 * @line_n: line number of of the opcode.
 */
void div(stack_t **stack, unsigned int line_n)
{
	int d;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_n);
		free_node();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n");
		exit(EXIT_FAILURE);
		free_node();
	}
	(*stack) = (*stack)->next;
	d = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = d;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
