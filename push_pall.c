#include "monty.h"

/**
 * shared_top - a function that pushes elements in the stack
 * @head: the head pointer, points to the first element in the stack
 * @count_line: counts the number of nodes in the stack
 * Return: nothing
 */

void shared_top(stack_t **head, unsigned int count_line)
{
	stack_t *h;
	int len_count, auxil;

	h = *head;
	while (h)
	{
		h = head->next;
		len_count++;
	}
	if (len_count < 2)
	{
		fprintf(stderr,)
	}
}
