#include "monty.h"

/**
 * ini_file - checks arguments in correct monty file
 * @argc: the argument count
 * @argv: the argument vector
 *
 * Return: 0 at success 1 otherwise
 */

int ini_file(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (1);
	}
	if (access(argv[1], F_OK & R_OK) != 0)
	{
		fprintf(stderr, "Error: Can't open file  %s\n", argv[1]);
		return (1);
	}
	return (0);
}

/**
 * file_open - the opens a file
 * @name_f: the name of file
 *
 * Return: NULL at fail otherwise file descripter
 */

FILE *file_open(char *name_f)
{
	FILE *fd;

	fd = fopen(name_f, "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name_f);
		return (NULL);
	}
	return (fd);
}
