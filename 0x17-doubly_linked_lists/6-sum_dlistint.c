#include "lists.h"

/**
 * sum_dlistint - return the sum of all nodes in a dlistint list
 * @head: pointer to head node of the doubly linked list
 * Return: sum of all nodes, or 0 if list is empty
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;
	dlistint_t *current;

	for (current = head; current != NULL; current = current->next)
		sum += current->n;

	return (sum);
}
