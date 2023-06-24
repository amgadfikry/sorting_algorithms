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
 * knuth - calculate knuth sequence
 * @size: size of array claculated
 * Return: gap to start with it
 */

size_t knuth(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = 3 * gap + 1;

	return (gap);
}

/**
 * shell_sort - sort array in ascending order
 * using shell sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void shell_sort(int *array, size_t size)
{
	int gap = knuth(size) / 3;
	int i, j;

	for (gap = knuth(size) / 3; gap > 0; gap /= 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (array[j + gap] < array[j])
					swap_elements(&array[j + gap], &array[j]);
			}
		}
		print_array(array, size);
	}
}
