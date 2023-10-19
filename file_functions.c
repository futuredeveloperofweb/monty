#include "monty.h"

/**
 * open - open a file
 * @f_name: the file name
 */

void open(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", f_name);
		free_node();
		exit(EXIT_FAILURE);
	}
	_read(fd);
	fclose(fd);
}

/**
 * _read - read a file
 * @fd: a pointer to the file descriptor
 */

void _read(FILE *fd)
{
	int line_n, fmt = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (line_n = 1; getline(&buffer, &l, fd) != -1; line_n++)
	{
		fmt = separat(buffer, line_n, fmt);
	}
	free(buffer);
}

/**
 * separat - separate each line into a command
 * @buffer: where to put the commands of each line
 * @line_n: line number
 * @fmt:  storage format
 * Return: Returns 0 if stack, 1 if queue.
 */

int separat(char *buffer, int line_n, int fmt)
{
	char *op_c, *val;
	const char *del = "\n ";

	if (buffer == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_node();
		exit(EXIT_FAILURE);
	}
	op_c = strtok(buffer, del);
	if (op_c == NULL)
		return (fmt);
	val = strtok(NULL, del);

	if (strcmp(op_c, "stack") == 0)
		return (0);
	if (strcmp(op_c, "queue") == 0)
		return (1);

	find_fct(op_c, val, line_n, fmt);
	return (fmt);
}

/**
 * find_fct - find the right function to work with
 * @op_c: the opcode
 * @val: the argument of opcode
 * @fmt: storage format
 * @line_n: line number
 */
void find_fct(char *op_c, char *val, int line_n, int fmt)
{
	int i;
	int f;

	instruction_t f_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{NULL, NULL}
	};

	if (op_c[0] == '#')
		return;

	for (f = 1, i = 0; f_list[i].opcode != NULL; i++)
	{
		if (strcmp(op_c, f_list[i].opcode) == 0)
		{
			call_fct(f_list[i].f, op_c, val, line_n, fmt);
			f = 0;
		}
	}
	if (f == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_n, op_c);
		free_node();
		exit(EXIT_FAILURE);
	}
}

/**
 * call_fct - call the function to use
 * @fct: a pointer to the function to use
 * @op_c: the opcode.
 * @val: numeric value.
 * @line_n: line numeber
 * @fmt: Format specifier
 */
void call_fct(op_func fct, char *op_c, char *val, int line_n, int fmt)
{
	stack_t *node;
	int f;
	int i;

	f = 1;
	if (strcmp(op_c, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val += 1;
			f = -1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_n);
			free_node();
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_n);
				free_node();
				exit(EXIT_FAILURE);
			}
		}
		node = make_node(atoi(val) * f);
		if (fmt == 0)
			fct(&node, line_n);
		if (fmt == 1)
			add_queue(&node, line_n);
	}
	else
		fct(&head, line_n);
}
