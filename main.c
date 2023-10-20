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
        global_t vg;

        sfd = check_file(argc, argv);
        _start_vg(sfd);
        num_lines = getline(&vg.buffer, &size, sfd);
        while (num_lines != -1)
        {
                len[0] = _strtoky(vg.buffer, " \t\n");
                if (len[0] && len[0][0] != '#')
                {
                        f = implement_opcodes(len[0]);

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
