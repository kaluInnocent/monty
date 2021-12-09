#include "monty.h"

/**
* op_func - function selects the required operation for execution
* @node: a pointer to a node
* @str: opcode argument
* @line_count: count of the number of lines
* Return: A pointer to the required operator function
*/

void op_func(stack_t **node, char *str, unsigned int line_count)
{
	instruction_t instruc[] = OPERATORS;
	int j = 0;

	if (!strcmp(str, "node"))
	{
		global.data = 1;
		return;
	}
	if (!strcmp(str, "queue"))
	{
		global.data = 0;
		return;
	}
	while (instruc[j].opcode)
	{
		if (strcmp(instruc[j].opcode, str) == 0)
		{
			instruc[j].f(node, line_count);
			return;
		}
		j++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_count, str);
	exit(EXIT_FAILURE);
}
