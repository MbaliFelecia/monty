#include "monty.h"

void global_data(void);
global_data_t globe_data;

/**
 * main - receives command line arguments
 * @argc: number of argument count
 * @argv: number of argument vectors
 *
 * Return: 0 at success and 1 otherwise
 */

int main(int argc, char **argv)
{
	int file_status;
	FILE *bc_file;
	char *opcode_tokens[2] = {NULL, NULL};
	void (*op_f)(stack_t **stack, unsigned int line_number);

	file_status = ini_file(argc, argv);
	if (file_status == 1)
		exit(EXIT_FAILURE);
	
	bc_file = file_op(argv[1]);
	if (bc_file == NULL)
		exit(EXIT_FAILURE);

	global_data();
	globe.bc_file = bc_file;
	globe.buff = rd_line(bc_file);
	while (globe.buff)
	{
		opcode_tokens[0] = strtok(globe.buff, " \t\n");
		opcode_tokens[1] = strtok(NULL, " \t\n");
		if (opcode_tokens[0] && opcode_tokens[0][0] != '#')
		{
			f = get_opcode(opcode_tokens[0]);
			if (f == NULL)
			{
				fprintf(stderr, "L%u: " globe.count_line);
				fprintf(stderr, "unkown instruction %s\n", opcode_tokens[0]);
				trm_global();
				exit(EXIT_FAILURE);
			}
			globe.arg = opcode_tokens[1];
			f(&globe.head, globe.count_line);
		}
		free(globe.buff);
		globe.buff = rd_line(bc_file);
		globe.count_line++;
	}
	trm_global();
	return (0);
}