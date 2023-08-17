#include "lists.h"

/**
 * insert_dnodeint_at_idx - insert a new node at given position
 * @h: double pointer to head
 * @idx: index to insert into
 * @n: value to store in new node
 * Return: Address of new node, or NULL if failed
 */
dlistint_t *insert_dnodeint_at_idx(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int c;
	dlistint_t *tmp, *prev, *new;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->prev = NULL;
		new->next = *h;
		if (*h)
			(*h)->prev = new;
		*h = new;
		return (new);
	}
	prev = NULL;
	tmp = *h;
	for (c = 0; tmp && c < idx; c++)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	if (!prev)
	{
		free(new);
		return (NULL);
	}
	new->prev = prev;
	new->next = tmp;
	prev->next = new;
	if (tmp)
		tmp->prev = new;
	return (new);
}
