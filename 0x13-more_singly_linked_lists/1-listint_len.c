#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @h: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{
size_t num_nodes = 0;
const listint_t *current_node;

for (current_node = h; current_node != NULL; current_node = current_node->next)
{
num_nodes++;
}

return (num_nodes);
}
