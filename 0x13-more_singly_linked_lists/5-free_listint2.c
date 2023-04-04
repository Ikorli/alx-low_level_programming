#include "lists.h"

/**
 * free_listint2 - frees a linked list
 * @head: pointer to the listint_t list to be freed
 */
void free_listint2(listint_t **head)
{
listint_t *current, *temp;

if (head == NULL)
return;

current = *head;
while (current != NULL)
{
temp = current->next;
free(current);
current = temp;
}
*head = NULL;
}
