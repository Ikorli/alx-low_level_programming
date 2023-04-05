#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list.
 * @h: Pointer to a pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *tmp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	while (current != NULL)
	{
		count++;
		tmp = current;
		current = current->next;
		if (tmp < current)
			free(tmp);
		else
		{
			*h = NULL;
			return (count);
		}
	}
	*h = NULL;
	while (*h != NULL)
	{
		tmp = *h;
		*h = (*h)->next;
		free(tmp);
		count++;
	}
	return (count);
}
