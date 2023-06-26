#include "sort.h"

/**
 * swap_elements - swap two elements in array
 * @first: first element to swap
 * @second: second element to swap
 * Return: nothing
 */

void swap_elements(int *first, int *second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

/**
 * heaping - max heap tree
 * @array: pointer to array
 * @start: start comparing index
 * @num: end of current tree
 * @size: full size of array
 * Return: nothing
 */

void heaping(int *array, int start, int num, size_t size)
{
	int p = start, leaf;

	while (p * 2 + 1 <= num)
	{
		leaf = p * 2 + 1;
		if (leaf + 1 <= num && array[leaf] < array[leaf + 1])
			leaf++;
		if (array[p] < array[leaf])
		{
			swap_elements(&array[leaf], &array[p]);
			print_array(array, size);
			p = leaf;
		}
		else
			return;
	}
}

/**
 * heap_sort - sort array in ascending order using
 * algorithm of heap sort
 * @array: pointer to arrary
 * @size: size of array
 * Return: nothing
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heaping(array, i, (int)size - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		swap_elements(&array[0], &array[i]);
		print_array(array, size);
		heaping(array, 0, i - 1, size);
	}
}
