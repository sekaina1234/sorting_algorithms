#include "sort.h"
/**
 * insertion_sort_list - insertion sorts a doubly-linked list
 * @list: address of pointer to head node
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *sorted, *tmp;
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
sorted = *list;
current = sorted->next;
while (current != NULL)
{
tmp = current;
current = current->next;
while (tmp->prev != NULL && tmp->n < tmp->prev->n)
{
tmp->prev->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = tmp->prev;
tmp->next = tmp->prev;
tmp->prev = tmp->prev->prev;
tmp->next->prev = tmp;
if (tmp->prev == NULL)
*list = tmp;
else
tmp->prev->next = tmp;
print_list((const listint_t *)*list);
}
}
}
