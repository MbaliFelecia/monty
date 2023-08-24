#include "monty.h"

/**
 * rd_line - reads lines from a file
 * @bytecode_file: the pointer
 *
 * Return: the lines content
 */

char *rd_line(FILE *bytecode_file)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t real_read;

	real_read = getline(&line, &len, bytecode_file);
	if (real_read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
