#include "monty.h"
#include "errors.h"

/**
 * get_node - get a node located at nth index
 * @head: pointer to the list
 * @index: the index of the node desired
 *
 * Return: address of the node, NULL if error
 */
stack_t *get_node(stack_t *head, unsigned int index)
{
	unsigned int i = 0;

	if (!head)
		return (NULL);
	while (head && i < index)
	{
		head = head->next;
		i++;
	}

	return (head ? head : NULL);
}
/**
 * list_len - returns the number of nodes on a list
 * @h: pointer to the list
 *
 * Return: number of nodes
 */
size_t list_len(const stack_t *h)
{
	size_t nodes = 0;

	if (!h)
		return (0);
	while (h)
	{
		nodes++;
		h = h->next;
	}

	return (nodes);
}
/**
 * insert_node - inserts a node at given index
 * in a list
 * @h: pointer to the list
 * @idx: index of the node to insert
 * @n: data to insert
 * Return: pointer to the new list
 */
stack_t *insert_node(stack_t **h, unsigned int idx, int n)
{
	unsigned int i;
	stack_t *new;
	stack_t *temp = *h;

	if (idx == 0)
		return (add_top(h, n));
	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			if (temp->next == NULL)
				return (add_end(h, n));
			new = malloc(sizeof(stack_t));
			if (!new || !h)
				return (NULL);
			new->n = n;
			new->next = NULL;
			new->next = temp->next;
			new->prev = temp;
			temp->next->prev = new;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}
	return (NULL);
}
