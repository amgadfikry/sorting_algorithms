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
 * bubble_sort - sorting array in ascending order with
 * bubble sorting algorithm
 * @array: array pointer
 * @size: size of array
 * Return: nothing
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, swap = 0;

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap = 1;
				swap_elements(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
		if (swap == 0)
			break;
	}
}
