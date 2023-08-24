#include "monty.h"

/**
 * global_data - initialise globral variable
 */

void global_data(void)
{
	globe.q_s_alt = 1;
	globe.count_line = 1;
	globe.arg = NULL;
	globe.bytecode_file = NULL;
	globe.head = NULL;
}

/**
 * trm_global - terminates global variable
 */

void trm_global(void)
{
	/*free_dlistint(globe.head);*/
	free(globe.buff);
	fclose(globe.bytecode_file);
}
