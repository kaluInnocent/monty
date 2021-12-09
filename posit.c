#include "monty.h"

/**
* swap - function swaps the top elements of the stack
* @head: Pointer to a pointer to the top of the stack
* @line_number: number of lines
* Return: void
*/
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp = (*head)->next;

	if (head == NULL || *head == NULL || !((*head)->next))
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *head;
	temp->next = *head;
	(*head)->prev = temp;
	temp->prev = NULL;
	*head = temp;
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
	stack_t *temp = *head;

	(void) line_number;

	if (head == NULL || *head == NULL)
		return;
	while (temp->next)
		temp = temp->next;
	temp->next = *head;
	(*head)->prev = temp;
	*head = (*head)->next;
	(*head)->prev->next = NULL;
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
	stack_t *ptr = *head;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	(void) line_number;

	while (ptr->next)
		ptr = ptr->next;
	ptr->next = *head;
	ptr->prev->next = NULL;
	ptr->prev = NULL;
	(*head)->prev = ptr;
	(*head) = ptr;

}
