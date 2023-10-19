#include "monty.h"

/**
 * nop - does nothing
 * @stack: pointer to stack.
 * @line_number: line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * swap - swap the top two elements of the stack.
 * @stack: pointer to stack.
 * @line_number: line number of of the opcode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_type2(8, line_number, "swap");
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
 * @line_number: line number of of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_type2(8, line_number, "add");

	(*stack) = (*stack)->next;
	s = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - substruct the top two elements of the stack.
 * @stack: pointer to stack.
 * @line_number: line number of of the opcode.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	int s;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		err_type2(8, line_number, "sub");

	(*stack) = (*stack)->next;
	s = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = s;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
