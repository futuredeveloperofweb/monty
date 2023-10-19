#include "monty.h"

/**
 * open - open a file
 * @f_name: the file name
 */

void open(char *f_name)
{
	FILE *fd = fopen(f_name, "r");

	if (f_name == NULL || fd == NULL)
		err_type(2, f_name);

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
	char *opcode, *val;
	const char *del = "\n ";

	if (buffer == NULL)
		err_type(4);
	opcode = strtok(buffer, del);
	if (opcode == NULL)
		return (fmt);
	val = strtok(NULL, del);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_fct(opcode, val, line_n, fmt);
	return (fmt);
}

/**
 * find_fct - find the right function to work with
 * @opcode: the opcode
 * @val: the argument of opcode
 * @fmt: storage format
 * @line_n: line number
 */
void find_fct(char *opcode, char *val, int line_n, int fmt)
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

	if (opcode[0] == '#')
		return;

	for (f = 1, i = 0; f_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, f_list[i].opcode) == 0)
		{
			call_fct(f_list[i].f, opcode, val, line_n, fmt);
			f = 0;
		}
	}
	if (f == 1)
		err_type(3, line_n, opcode);
}

/**
 * call_fct - call the function to use
 * @func: a pointer to the function to use
 * @op_c: the opcode.
 * @val: numeric value.
 * @line_n: line numeber
 * @fmt: Format specifier
 */
void call_fct(op_func func, char *op_c, char *val, int line_n, int fmt)
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
			err_type(5, line_n);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err_type(5, line_n);
		}
		node = make_node(atoi(val) * f);
		if (fmt == 0)
			func(&node, line_n);
		if (fmt == 1)
			add_queue(&node, line_n);
	}
	else
		func(&head, line_n);
}
