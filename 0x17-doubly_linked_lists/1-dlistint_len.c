#include "lists.h"

/**
 * dlistint_len - Returns the number of elements in a dlistint_t list.
 * @h: A pointer to the head of the list.
 * Return: The number of elements in the list.
 */
size_t dlistint_len(const dlistint_t *h)
{
const dlistint_t *current = h;
size_t count = 0;

while (current != NULL)
{
count++;
current = current->next;
}

return (count);
}
