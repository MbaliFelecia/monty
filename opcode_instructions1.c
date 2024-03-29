#include "monty.h"

/**
 * push - pushes an element to the stack
 *
 * @stack: head of the linked list
 * @line_number : line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
	int n, j;

	if (!globe.arg)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		trm_global();
		exit(EXIT_FAILURE);
	}

	for (j = 0; globe.arg[j] != '\0'; j++)
	{
		if (!isdigit(globe.arg[j]) && globe.arg[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			trm_global();
			exit(EXIT_FAILURE);
		}
	}

	n = atoi(globe.arg);

	if (globe.q_s_alt == 1)
		add_dnodeint(stack, n);
	else
		add_dnodeint_end(stack, n);
}

/**
 * pall - prints all values on the stack
 *
 * @stack: head of the linked list
 * @line_number: line numbers
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack == NULL)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pint, stack empty\n");
		trm_global();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	if (stack == NULL || *stack == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_number);
		trm_global();
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = (*stack)->next;
	free(current);
}

/**
 * swap - swaps the top two elements of the stack
 *
 * @stack: head of the linked list
 * @line_number: line number
 * Return: no return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *stack;

	for (; tmp != NULL; tmp = tmp->next, m++)
		;

	if (m < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", line_number);
		trm_global();
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	tmp->prev = *stack;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
}
