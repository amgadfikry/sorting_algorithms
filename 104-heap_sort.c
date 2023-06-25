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

void heaping(int *array, int num, size_t size)
{
	int rt, lt, i = num;

	for (; i >= 0; i--)
	{
		lt = (i * 2) + 1;
		rt = (i * 2) + 2;
		if (lt <= num && array[lt] > array[i])
		{
			swap_elements(&array[lt], &array[i]);
			print_array(array, size);
		}
		if (rt <= num && array[rt] > array[i])
		{
			swap_elements(&array[rt], &array[i]);
			print_array(array, size);
		}
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
	for (i = size - 1; i > 0; i--)
	{
		heaping(array, i, size);
		swap_elements(&array[0], &array[i]);
		print_array(array, size);
	}
}
