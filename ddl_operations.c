#include "monty.h"

/**
* queue - function adds a node to a queue
* @head: A pointer to a pointer to the top of the queue
* @n: data to be added
* Return: 0 on success and -1 if it fails
*/
stack_t *queue(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));
	stack_t *ptr = *head;

	if (new == NULL)
	{
		free(new);
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
	
	return (*head);
}

/**
* add_end_node - function adds a node to a stack
* @head: pointer to a pointer to the top of tha stack
* @n: data to be added
* Return: 0 if successful, -1 if it failed
*/
stack_t *add_end_node(stack_t **head, int n)
{
	stack_t *new = make_node(n);

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(new);
		return (NULL);
	}
	if (!*head)
		*head = new;
	else
	{
		(*head)->prev = new;
		new->next = *head;
		*head = new;
	}
	return (*head);
}

/**
* delete_end_node - function deletes a node from a stack
* @head: Pointer to a pointer to the top of the node
* Return: void
*/
void delete_end_node(stack_t **head)
{
	stack_t *ptr = *head;

	if (head == NULL || *head == NULL)
		return;
	if (!(*head)->next)
	{
		*head = NULL;
		free(ptr);
	}
	else
	{
		*head = (*head)->next;
		if ((*head)->next)
			(*head)->prev = NULL;
		free(ptr);
	}
}

/**
* free_list - function frees a doubly linked list
* @head: pointer to the head node
* Return: void
*/
void free_list(stack_t *head)
{
	if (head == NULL)
		return;
	while (head && head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
