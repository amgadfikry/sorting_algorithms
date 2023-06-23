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
 * selection_sort - sort array in ascending order
 * using selection sort algorithm
 * @array: point to array
 * @size: size of array
 * Return: nothing
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *swap;

	for (i = 0; i < size; i++)
	{
		swap = &array[i];
		for (j = i + 1; j < size; j++)
		{
			if (*swap > array[j])
				swap = &array[j];
		}
		swap_elements(swap, &array[i]);
		print_array(array, size);
	}
}
