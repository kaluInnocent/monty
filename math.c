#include "monty.h"

/**
* add_node - function adds the top two elements of the stack
* @head: A pointer to a pointer to the top of the stack
* @line_number: number of nodes
* Return: void
*/
void add_node(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n += (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
* sub_node - function subtracts the top element of the stack from the second
* @head: A pointer to a pointer to the top of the stack
* @line_number: number of nodes
* Return: void
*/
void sub_node(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n -= (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
* div_node -  function divides the second top element of the stack by the
*	top element of the stack.
* @head: pointer to a pointer to the top of the stack
* @line_number: number of nodes
* Return: void
*/

void div_node(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n != 0)
	{
		(*head)->next->n /= (*head)->n;
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
* mul_node - function multiplies the second top element of the stack
*	with the top element of the stack.
* @head: A pointer to a pointer to the top of the stack
* @line_number: The number of lines
* Return: Void
*/

void mul_node(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n *= (*head)->n;
	*head = (*head)->next;
	free((*head)->prev);
	(*head)->prev = NULL;
}

/**
* mod_node - function computes the rest of the division of the second
*	top element of the stack by the top element of the stack
* @head: A pointer to a pointer to the top of the stack
* @line_number: number of lines
* Return: void
*/
void mod_node(stack_t **head, unsigned int line_number)
{
	if (head == NULL || *head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n != 0)
	{
		(*head)->next->n  %= (*head)->n;
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
}
