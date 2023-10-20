#include "monty.h"

/**
 * _free_vg - frees the global variables
 *
 * Return: void
 */
void _free_vg(void)
{
	_freedlist(vg.head);
	free(vg.buffer);
	fclose(vg.fd);
}

/**
 * _start_vg - initializes the global variables
 *
 * @sfd: file descriptor
 * Return: void
 */

void _start_vg(FILE *sfd)
{
	vg.lifo = 1;
	vg.cont = 1;
	vg.arg = NULL;
	vg.head = NULL;
	vg.fd = sfd;
	vg.buffer = NULL;
}

/**
 * check_file - checks if the file exists and can be opened
 * @argc: argument count
 * @argv: argument vector
 * Return: file struct
 */

FILE *check_file(int argc, char *argv[])
{
	FILE *sfd;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	sfd = fopen(argv[1], "r");

	if (sfd == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (sfd);
}
