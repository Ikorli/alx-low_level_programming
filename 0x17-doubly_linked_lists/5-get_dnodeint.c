#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint list
 * @head: Pointer to the head of the list
 * @index: Index position of the node
 * Return: Pointer to the nth node, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	dlistint_t *current = head;
	unsigned int count = 0;

	while (current != NULL)
	{
		if (count == index)
		{
			return (current);
		}
		count++;
		current = current->next;
	}

	return (NULL);
}
