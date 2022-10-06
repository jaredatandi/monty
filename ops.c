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
		return (new); }

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new;
	new->prev = tmp;

	return (new);
}

/**
 * p_list - prints a linked list
 * @head: pointer to the list
 *
 * Return: number of in the list
 */
size_t p_list(const stack_t *head)
{
	size_t nodes = 0;

	if (!head)
		return (0);
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
		nodes++;
	}

	return (nodes);
}

/**
 * delete_node - deletes a node at a specific index
 * @head: pointer to the list
 * @index: index of the node to delete
 *
 * Return: 1 on success, -1 on error
 */
int delete_node(stack_t **head, unsigned int index)
{
	stack_t *temp = *head;
	unsigned int i = 0;

	if (!index)
	{
		(*head) = temp->next;
		if (temp->next)
			temp->next->prev = NULL;
		temp->next = NULL;
		free(temp);
		return (1);
	}

	while (i < index)
	{
		temp = temp->next;
		i++;
		if (!temp)
			return (0);
	}

	temp->prev->next = temp->next;
	if (temp->next)
		temp->next->prev = temp->prev;
	free(temp);

	return (1);
}
