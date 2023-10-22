#include "monty.h"

/**
 * pchar_ - print the char value of the first element
 *
 * @head: head of the linked list
 * @count_line: the number of line
 * Return: void
 */
void pchar_(stack_t **head, unsigned int count_line)
{
	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", count_line);
		_free_vg();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
