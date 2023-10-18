#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: Pointer to the top node of the stack.
 * @line_nb: the number of the line
 */
void swap(stack_t **stack, unsigned int line_nb)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_type2(8, line_nb, "swap");
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
 * add - add the top two node in stack
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_nb: Interger representing the line number of of the opcode.
 */
void add(stack_t **stack, unsigned int line_nb)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_type2(8, line_nb, "add");
	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - doesn’t do anything
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_nb: Interger representing the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_nb)
{
	(void)stack;
	(void)line_nb;
}

/**
 * sub - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_nb: Interger representing the line number of of the opcode.
 */
void sub(stack_t **stack, unsigned int line_nb)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_type2(8, line_nb, "sub");
	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

