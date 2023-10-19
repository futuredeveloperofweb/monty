#include "monty.h"

/**
 * make_node - create a node.
 * @n: the value inside the node.
 * Return: a pointer to the node, Otherwise NULL.
 */
stack_t *make_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_node();
		exit(EXIT_FAILURE);
	}
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_node - free nodes in the stack.
 */
void free_node(void)
{
	stack_t *tm;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		tm = head;
		head = head->next;
		free(tm);
	}
}

/**
 * add_queue - adds nodes to queue.
 * @new: a pointer to node to add
 * @line_n: line number
 */
void add_queue(stack_t **new, __attribute__((unused))unsigned int line_n)
{
	stack_t *tm;

	if (new == NULL || *new == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new;
		return;
	}
	tm = head;
	while (tm->next != NULL)
		tm = tm->next;
	tm->next = *new;
	(*new)->prev = tm;
}
