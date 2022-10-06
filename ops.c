#include "monty.h"
#include "errors.h"

/**
 * add_top - adds a node to the top of a list
 * @h: pointer to the first node
 * @n: integer to add
 * Return: pointer to the new list, NULL if error
 */
stack_t *add_top(stack_t **h, const int n)
{
	stack_t *new;

	if (!h)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *h;
	new->prev = NULL;

	if (*h)
		(*h)->prev = new;
	*h = new;
	return (new);
}

/**
 * add_end - adds to the end of alist
 * @h: pointer to the beginning of the list
 * @n: integer to insert
 *
 * Return: pointer to the new list, NULL if error
 */
stack_t *add_end(stack_t **h, const int n)
{
	stack_t *new, *tmp;

	tmp = *h;

	if (!h)
		return (NULL);
	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (*h == NULL)
	{
		new->prev = NULL;
		*h = new;
		return (new);
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;

	return (new);
}


