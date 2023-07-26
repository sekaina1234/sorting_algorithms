#include "sort.h"
/**
 * swap - swaps 2 nodes in a doubly-linked list
 * @a: address of first node
 * @b: address of second node
 *
 * Return: void
 */
void swap(listint_t **list, listint_t *a, listint_t *b)
{
if (a->prev)
a->prev->next = b;
if (b->next)
b->next->prev = a;
a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
if (b->prev == NULL)
*list = b;
}
/**
 * cocktail_sort_list - sorts a doubly linked list using Cocktail Shaker Sort
 * @list: address of pointer to the head of the list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
int swapped = 1;
listint_t *current;
if (!list || !*list)
return;
while (swapped)
{
swapped = 0;
for (current = *list; current->next != NULL; current = current->next)
{
if (current->n > current->next->n)
{
swap(list, current, current->next);
print_list((const listint_t *)*list);
swapped = 1;
}
}
if (!swapped)
break;
swapped = 0;
for (; current->prev != NULL; current = current->prev)
{
if (current->n < current->prev->n)
{
swap(list, current->prev, current);
print_list((const listint_t *)*list);
swapped = 1;
}
}
}
}
