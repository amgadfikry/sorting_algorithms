#include "sort.h"

/**
 * swap_nodes - swap two nodes position without
 * change int inside it
 * @first: first node
 * @second: second node
 * Return: nothing
 */

void swap_nodes(listint_t *first, listint_t *second)
{
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	if (first->prev)
		first->prev->next = second;
	second->prev = first->prev;
	first->prev = second;
	second->next = first;
}

/**
 * cocktail_sort_list - sort double link list in ascending order
 * using cocktail sort algorithm
 * @list: pointer to pointer of list
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr = *list;
	listint_t *right = NULL, *left = NULL;
	int swap = 1;

	while (swap)
	{
		swap = 0;
		while (ptr->next != right)
		{
			if (ptr->n > ptr->next->n)
			{
				swap_nodes(ptr, ptr->next);
				swap = 1;
				print_list(*list);
			}
			else
				ptr = ptr->next;
		}
		right = ptr;
		ptr = right->prev;
		if (swap == 0)
			break;
		swap = 0;
		while (ptr->prev != left)
		{
			if (ptr->n < ptr->prev->n)
			{
				swap_nodes(ptr->prev, ptr);
				swap = 1;
				if (ptr->prev == NULL)
					*list = ptr;
				print_list(*list);
			}
			else
				ptr = ptr->prev;
		}
		left = ptr;
		ptr = left->next;
	}
}
