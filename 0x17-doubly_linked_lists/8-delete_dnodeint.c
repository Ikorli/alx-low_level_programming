#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete node at index of a `dlistint_t` LL
 * @head: double pointer to head of LL
 * @index: index position to remove from LL
 * Return: 1 if succeeded, -1 if failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *prev;

	if (*head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = (*head)->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (index > 0 && current != NULL)
	{
		prev = current;
		current = current->next;
		index--;
	}

	if (current == NULL)
		return (-1);

	prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = prev;

	free(current);

	return (1);
}
