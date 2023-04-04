#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *slow = head, *fast = head;

	while (fast && fast->next)
	{
		nodes++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			printf("-> [%p] %d\n", (void *)slow, slow->n);
			printf("Loop detected, exiting with status 98\n");
			exit(98);
		}
	}

	/* Print remaining nodes in the list */
	while (slow)
	{
		nodes++;
		printf("[%p] %d\n", (void *)slow, slow->n);
		slow = slow->next;
	}

	return (nodes);
}
