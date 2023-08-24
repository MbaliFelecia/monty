#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end
 * of a stack_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *h, *new;

	h = (*head);

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		new->prev = NULL;
		return (new);
	}
	while (h->next != NULL)
		h = h->next;
	h->next = new;
	new->prev= h;
	return (new);
}

/**
 * add_dnodeint - adds a new node at the beginning
 * of a stack_t list
 *
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
stack_t *add_dnodeint(stackt_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->prev = NULL;
	

	if (head != NULL)
	{
		new->next = (*head);
		if (*head != NULL)
		{
			(*head)->prev = new;
		}
		*head = new;
	}
	else
		new->next = NULL;

	return (new);
}

/**
 * free_dlistint - frees the doubly linked list
 *
 * @head: head of the list
 * Return: no return
 */

void free_dlistint(stack_t *head)
{
	stack_t *h;
	
	while (head)
	{
		h = head-> next;
		free(head);
		head = h;
	}
}
