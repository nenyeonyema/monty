#include "monty.h"

/**
 *add_new_end_node - a function that adds a node
 *at the end of the doubly link list
 *@head: first position of linked list
 *@num: data
 *Return: a pointer to new end node
 */
stack_t *add_new_end_node(stack_t **head, const int num)
{
	stack_t *ptr, *current;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(stack_t));
	if (!ptr)
	{
		dprintf(2, "Error: malloc failed\n");
		_free_vg();
		exit(EXIT_FAILURE);
	}

	ptr->n = num;
	if (*head == NULL)
	{
		ptr->next = *head;
		ptr->prev = NULL;
		*head = ptr;
		return (*head);
	}
	current = *head;
	while (current->next)
		current = current->next;
	ptr->next = current->next;
	ptr->prev = current;
	current->next = ptr;
	return (current->next);
}

/**
 *add_new_beg_node - add a note at the begining of the doubly link list
 *@head: first position of linked list
 *@num: data
 *Return: the head pointer to a doubly linked list
 */

stack_t *add_new_beg_node(stack_t **head, const int num)
{
	stack_t *ptr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(stack_t));
	if (!ptr)
	{
		dprintf(2, "Error: malloc failed\n");
		_free_vg();
		exit(EXIT_FAILURE);
	}
	ptr->n = num;
	if (*head == NULL)
	{
		ptr->next = *head;
		ptr->prev = NULL;
		*head = ptr;
		return (*head);
	}
	(*head)->prev = ptr;
	ptr->next = (*head);
	ptr->prev = NULL;
	*head = ptr;
	return (*head);
}

/**
 * _freedlist - a function that frees a doubly list
 * @head: head points to first node on the list
 * Return: void
 */
void _freedlist(stack_t *head)
{
	stack_t *ptr;

	while ((ptr = head) != NULL)
	{
		head = head->next;
		free(ptr);
	}
}
