#include "sort.h"
/**
 * insertion_sort_list - Sorts a doubly linked list
 * of integers in ascending order
 *                        using the Insertion sort algorithm.
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
listint_t *current, *key, *sorted;
sorted = *list;
current = sorted->next;
while (current != NULL)
{
key = current;
current = current->next;
while (key->prev != NULL && key->n < key->prev->n)
{
if (key->next != NULL)
key->next->prev = key->prev;
key->prev->next = key->next;
key->next = key->prev;
key->prev = key->prev->prev;
key->next->prev = key;
if (key->prev == NULL)
*list = key;
else
key->prev->next = key;
print_list(*list);
}
}
}
