#include "monty.h"

/**
 * open - open the file
 * @f_nm: the name of the file
 */
void open(char *f_nm)
{
	FILE *fd = fopen(f_nm, "r");

	if (f_nm == NULL || fd == NULL)
		error_type(2, f_nm);
	_read(fd);
	fclose(fd);
}

/**
 * _read - read the file
 * @fd: the file descriptor
 */
void _read(FILE *fd)
{
	int line_nb, f = 0;
	char *buffer = NULL;
	size_t l = 0;

	for (line_nb = 1; getline(&buffer, &l, fd) != -1; line_nb++)
		f = separat(buffer, line_nb, f);
	free(buffer);
}

/**
 * separat - separat each line in the inpute to tokens
 * @buffer: where the stdin will be
 * @line_nb: the nb of the line
 * @f: how the nodes will be stored
 * Return: 0 if stack, 1 if queue
 */
int separat(char *buffer, int line_nb, int f)
{
	char *op_c, *val;
	const char *del = "\n";

	if (buffer == NULL)
		error_type(4);
	op_c = strtok(buffer, del);
	if (op_c == NULL)
		return (f);
	val = strtok(NULL, del);
	if (strcmp(op_c, "stack") == 0)
		return (0);
	if (strcmp(op_c, "queue") == 0)
		return (1);
	find_fct(op_c, val, line_nb, f);
	return (f);
}

/**
 * find_fct - search for the function to use
 * @opcode: the opcode
 * @val: the arg of the opcode
 * @f: how the nodes will be stored
 * @line_nb: the nb of the line
 */
void find_fct(char *opcode, char *val, int line_nb, int f)
{
	int i, fg;

	instruction_t fct_l[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;
	for (fg = 1, i = 0; fct_l[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, fct_l[i].opcode) == 0)
		{
			call_fct(fct_l[i].f, opcode, val, line_nb, f);
			fg = 0;
		}
	}
	if (fg == 1)
		error_type(3, line_nb, opcode);
}

/**
 * call_fct - call the function to use in the code
 * @fct: a pointer to the function to use
 * @op_c: the opcode string
 * @val: the arg of the opcode
 * @line_nb: the nb of the line
 * @f: how the nodes will be stored
 */
void call_fct(o_fct fct, char *op_c, char *val, int line_nb, int f)
{
	stack_t *node;
	int fg = 1, i = 0;

	if (strcmp(op_c, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val += 1;
			fg = -1;
		}
		if (val == NULL)
			error_type(5, line_nb);
		while (val[i] != '\0')
		{
			if (isdigit(val[i]) == 0)
				error_type(5, line_nb);
			i++;
		}
		node = mk_node(atoi(val) * fg);
		if (f == 0)
			fct(&node, line_nb);
		if (f == 1)
			add_queue(&node, line_nb);
	}
	else
		fct(&top, line_nb);
}
