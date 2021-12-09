#include "monty.h"
#include <ctype.h>

/**
* pall - function prints all the values on the stack, starting from the top
* @head: A pointer to a pointer to the top of the stack
* @line_number: number of lines
* Return: void
*/
void pall(stack_t **head, unsigned int line_number)
{
	(void) line_number;

	if (head == NULL || *head == NULL)
		return;
	while (*head)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
}

/**
* pint - function prints the value at the top of the stack
* @head: pointer to a pointer to the top of the stack
* @line_number: nmuber of lines
* Return: void
*/
void pint(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* pchar - function prints the char at the top of the stack
* @head: pointer to a pointer to the top of the stack
* @line_number: line count
* Return: void
*/
void pchar(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (isascii((*head)->n) == 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}

/**
* pstr - function prints the string starting at the top of the stack
* @head: A pointer to a pointer to thectop of the stack
* @line_number: number of lines
* Return: Void
*/
void pstr(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (*head)
	{
		if ((*head)->n != 0 && (isascii((*head)->n != 0)))
			putchar((char) (*head)->n);
		else
			break;
		*head = (*head)->next;
	}
	putchar('\n');
}

/**
* nop -function does nothing
* @head: pointer to pointer to the head of the stack
* @line_number: number of lines
* Return: nothing
*/
void nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
