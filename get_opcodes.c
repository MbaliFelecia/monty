#include "monty.h"

/**
 * get_opcode - selects the correct opcode to perform
 * @opc: opcode passed
 *
 * Return: pointer to the function which execites the opcode
 */
void (*get_opcode(char *opc))(stack_t **stack, unsigned int line_number)
{
	instruction_t instruct[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"queue", queue},
		{"stack", stack},
		{"swap", swap},
		/*{"add", add},*/
		{"nop", nop},
		{"sub", sub},
		{"mul", mul},
		{"div", _div},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i;

	for (i = 0; instruct[i].opcode; i++)
	{
		if (strcmp(instruct[i].opcode, opc) == 0)
			break;
	}

	return (instruct[i].f);
}
