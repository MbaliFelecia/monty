#include "monty.h"

/**
 * stack - sets the stack
 * @stcak: the head of the stack
 * @line_number: number of the line
 */

void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	globe.q_s_alt = 1;
}

/**
 * queue - sets the queue of the stack
 * @stack: the head of the stack
 * @line_number: the number of the line
 */

void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	globe.q_s_alt = 0;
}
