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
 * check_greater - check greater number and move it to
 * right most of list
 * @list: list original
 * @ptr: ptr of first element
 * @right: right most end
 * Return: 0 if no swap or 1 if swap
 */

int check_greater(listint_t **list, listint_t **ptr, listint_t **right)
{
	int swap = 0;
	listint_t *p = *ptr;

	while (p->next != *right)
	{
		if (p->n > p->next->n)
		{
			swap_nodes(p, p->next);
			swap = 1;
			if (p == *list)
				*list = p->prev;
			print_list(*list);
		}
		else
			p = p->next;
	}

	return (swap);
}

/**
 * check_lesser - check lesser number and move it to
 * left most of list
 * @list: list original
 * @ptr: ptr of first element
 * @left: left most end
 * Return: 0 if no swap or 1 if swap
 */

int check_lesser(listint_t **list, listint_t **ptr, listint_t **left)
{
	int swap = 0;
	listint_t *p = *ptr;

	while (p->prev != *left)
	{
		if (p->n < p->prev->n)
		{
			swap_nodes(p->prev, p);
			swap = 1;
			if (p->prev == NULL)
				*list = p;
			print_list(*list);
		}
		else
			p = p->prev;
	}

	return (swap);
}

/**
 * cocktail_sort_list - sort double link list in ascending order
 * using cocktail sort algorithm
 * @list: pointer to pointer of list
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *ptr = *list, *right = NULL, *left = NULL;
	int swap = 1;

	if (!list || !*list || !(*list)->next)
		return;
	while (swap)
	{
		swap = check_greater(&*list, &ptr, &right);
		right = ptr;
		ptr = right->prev;
		if (swap == 0)
			break;

		swap = check_lesser(&*list, &ptr, &left);
		left = ptr;
		ptr = left->next;
	}
}
