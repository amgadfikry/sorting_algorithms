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
 * insertion_sort_list - sort link list accord to inserton
 * algorithm with swap node not value
 * @list: pointer to pointer oh head of list
 * Return: nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *ptr, *back, *point;

	if (!*list || !(*list)->next)
		return;
	ptr = (*list)->next;
	while (ptr)
	{
		back = ptr->prev;
		if (ptr->n > back->n)
		{
			ptr = ptr->next;
			continue;
		}
		while (back)
		{
			point = back->next;
			if (point->n < back->n)
			{
				if (*list == back)
					*list = point;
				swap_nodes(back, point);
				if (ptr == point)
					ptr = back;
				back = point->prev;
				print_list(*list);
			}
			else
				back = back->prev;
		}
		ptr = ptr->next;
	}
}
