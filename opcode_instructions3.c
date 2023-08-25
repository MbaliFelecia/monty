#include "monty.h"

/**
 * rotr - rotates the stack
 * @stack: the head stack
 * @line_number: the line number
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	current->prev->next = NULL;
	(*stack)->prev = current;
	current->next = *stack;
	current->prev = NULL;
	(*stack) = current;
}

/**
 * rotl - rotates stack to flip to top
 * @stack: the head of the stack
 * @line _number: the number of line
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	while (current->next != NULL)
		current = current->next;
	current->next = *stack;
	(*stack)->prev = current;
	(*stack) = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current && current->n >= 32 && current->n <= 127)
	{
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
/**
 * pchar - prints characters from start of stack
 * @stack: the head of the stack
 * @line_number: the line number
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		trm_global();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 32 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		trm_global();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * mod - computes the top two elements in the stcak
 * @stack: the head stack
 * @line_number: the line number
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *delete_it;

	delete_it = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u ", line_number);
		fprintf(stderr, "can't mod, stack too short\n");
		trm_global();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		trm_global();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	free(delete_it);
}
