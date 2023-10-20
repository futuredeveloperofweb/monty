#include "monty.h"

/**
 * rotl - rotates the stack to the top.
 * @stack: pointer to stack
 * @line_n: line number of of the opcode.
 */
void rotl(stack_t **stack, unsigned int line_n)
{
	stack_t *tm = *stack;

	(void) line_n;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		return;
	while (tm->next)
		tm = tm->next;
	tm->next = (*stack);
	(*stack)->prev = tm;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: pointer to stack
 * @line_n: line number of of the opcode.
 */
void rotr(stack_t **stack, unsigned int line_n)
{
	stack_t *tm = *stack;

	(void) line_n;

	if (stack == NULL || (*stack) == NULL || (*stack)->next == NULL)
		return;
	while (tm->next)
		tm = tm->next;
	tm->next = *stack;
	tm->prev->next = NULL;
	tm->prev = NULL;
	(*stack)->prev = tm;
	(*stack) = tm;
}
