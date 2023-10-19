#include "monty.h"

stack_t *head = NULL;

/**
 * main - the main function
 * @argc: the args counter
 * @argv: array of strings arguments
 * Return: 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open(argv[1]);
	free_node();
	return (0);
}
