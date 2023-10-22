#include "monty.h"

glo_t vg;

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *sfd;
	size_t size = 256;
	ssize_t num_lines = 0;
	char *len[2] = {NULL, NULL};

	sfd = check_file(argc, argv);
	_start_vg(sfd);
	num_lines = getline(&vg.buffer, &size, sfd);

	while (num_lines != -1)
	{
		len[0] = _strtoky(vg.buffer, " \t\n");
		if (len[0] && len[0][0] != '#')
		{
			f = implement(len[0]);

			if (!f)
			{
				dprintf(2, "L%u: ", vg.cont);
				dprintf(2, "unknown instruction %s\n", len[0]);
				_free_vg();
				exit(EXIT_FAILURE);
			}
			vg.arg = _strtoky(NULL, " \t\n");
			f(&vg.head, vg.cont);
		}
		num_lines = getline(&vg.buffer, &size, sfd);
		vg.cont++;
	}
	_free_vg();

	return (0);
}
