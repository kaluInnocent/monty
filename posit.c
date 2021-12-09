#include "monty.h"

/**
* swap - function swaps the top elements of the stack
* @head: Pointer to a pointer to the top of the stack
* @line_number: number of lines
* Return: void
*/
void swap(stack_t **head, unsigned int line_number)
{
	int n = (*head)->n;

	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->n = (*head)->next->n;
	(*head)->next->n = n;
}

/**
* rotl - function rotates the stack to the top:
*	The top element becomes the last one,
*	and the second top element of the stack becomes the first one
* @head: A pointer to a pointer to the top of the stack
* @line_number: number of lines
* Return: Void
*/
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *top = *head, *ptr;
	stack_t *second = top->next;

	(void) line_number;

	if (head == NULL || *head == NULL)
		return;

	while ((*head)->next)
		*head = (*head)->next;
	ptr = (*head)->next;
	ptr = top;
	ptr->prev = *head;
	ptr->next = NULL;

	*head = second;
	(*head)->prev = NULL;
}
/**
* rotr - function rotates the stack to the bottom
* @head: pointer to the start of the stack
* @line_number: number of lines
* Return: void
*/
void rotr(stack_t **head, unsigned int line_number)
{
	stack_t *ptr = *head, *temp;

	(void) line_number;

	if (head == NULL || *head == NULL)
		return;

	while (ptr)
	{
		temp = ptr->prev;
		ptr->prev = ptr->next;
		ptr->next = temp;
		ptr = ptr->prev;
	}
	if (temp)
		*head = temp->prev;
}
