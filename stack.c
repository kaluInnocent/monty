#include "monty.h"

/**
* is_digit - function checks for an integer in  a string
* @str: string to be checked
* Return: 1 on sucess, 0 on failure
*/
int is_digit(char *str)
{
	if (!str || *str == '\0')
		return (0);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

/**
* is_num - function checks if a string is a number
* @str: string to be checked
* Return: a number, 0 otherwise
*/
int is_num(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		if (i < '0' || i > '9')
			return (0);
	return (1);
}


/**
* push - adds a node to the stack
* @head: A pointer to a pointer to the top stack
* @line_number: number of lines
* Return: void
*/
void push(stack_t **head, unsigned int line_number)
{
	char *n = global.arg;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (global.data == 1)
	{
		if (!add_end_node(head, atoi(global.arg)))
			exit(EXIT_FAILURE);
	}
	else
	{
		if (!queue(head, atoi(global.arg)))
			exit(EXIT_FAILURE);
	}
}

/**
* pop - function removes node at top of a stack
* @head: A pointer to a pointer to the top of the node
* @line_number: number of lines
* Return: void
*/
void pop(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		delete_end_node(head);
}
