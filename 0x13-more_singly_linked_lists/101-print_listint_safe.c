#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;
const listint_t *slow = head;
const listint_t *fast = head;

while (fast != NULL && fast->next != NULL)
{
count++;
printf("[%p] %d\n", (void *)slow, slow->n);
slow = slow->next;
fast = fast->next->next;

if (slow == fast)
{
printf("-> [%p] %d\n", (void *)slow, slow->n);
printf("List is looped\n");
exit(98);
}
}
if (fast != NULL)
{
count++;
printf("[%p] %d\n", (void *)slow, slow->n);
}
return (count);
}
