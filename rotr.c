#include "monty.h"

/**
 * rotr_ - a function that reverses the stack.
 * @head: head of the linked list
 * @count_line: the number of lines
 * Return: void
 */

void rotr_(stack_t **head, unsigned int count_line)
{
	stack_t *temp = NULL;
	(void)count_line;

	if (*head == NULL)
		return;

	if ((*head)->next == NULL)
		return;

	temp = *head;

	for (; temp->next != NULL; temp = temp->next)
		;

	temp->prev->next = NULL;
	temp->next = *head;
	temp->prev = NULL;
	(*head)->prev = temp;
	*head = temp;
}
