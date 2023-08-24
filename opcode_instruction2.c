#include "monty.h"
/**
 * add - adds two elements in the stack
 * @stack: the stack head
 * @line_number: the number of line in stack
 *
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *delete_it;

	delete_it = *stack;
	if (*stack == NULL || (*stack)->next ==  NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		trm_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (stack)->n + (*stack)->next->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
       free(delete_it);
}
/**
 * mul - mulitplies the two top elements of the stack
 * @stack: the head stack
 * @line_number: number line
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *delete_it;

	delete_it = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mul, stack too short\n");
		trm_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->n * (*stack)->next->n;
	(stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(delete_it);
}

/**
 * sub - subtracts the top two elements of the stack
 * @stack: the head stack
 * @line_number: the number of line in stack
 *
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack *delete_it;

	delete_it = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't sub, stack too short\n");
		trm_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(delete_it);
}
/**
 * nop - this will do nothing
 * @stack: the head of the stack
 * @line_number: the line number
 */

void nope(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * _div - divides top two elements of the stack
 * @stack: the head of the stack
 * @line_number: the line number
 */
void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *delete_it;

	delete_it = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't div, stacl too short\n");
		trm_global();
		exit(EXIT_FAILURE);
	}
	if ((*stack)-> == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		trm_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(delete_it);
}
