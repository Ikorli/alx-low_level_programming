#include "lists.h"

/**
 * print_dlistint - print all elements of a dlistint.
 * @h: type dlistint point of prev and next node
 * Return: Number of nodes in the list.
 */

size_t print_dlistint(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
