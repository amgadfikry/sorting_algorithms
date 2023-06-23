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
 * part - get pivot in array in it's position and
 * smaller numbers to left
 * @array: pointer to array
 * @start: start of array
 * @end: end of array
 * @size: size of array
 * Return: pivot index
 */

int part(int *array, int start, int end, size_t size)
{
	int index = start - 1, i, key = array[end];

	for (i = start; i < end; i++)
	{
		if (array[i] <= key)
		{
			index++;
			swap_elements(&array[i], &array[index]);
			if (i != index)
				print_array(array, size);
		}
	}
	swap_elements(&array[end], &array[index + 1]);
	if (index + 1 != end)
		print_array(array, size);
	return (index + 1);
}
/**
 * sorting - sort array to left and right accord to pivot
 * @array: array pointer
 * @start: start of sorting index
 * @end: end os sort index
 * @size: size of array
 * Return: nothing
 */

void sorting(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = part(array, start, end, size);
		sorting(array, start, pivot - 1, size);
		sorting(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sort array in ascending order
 * using quick sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	sorting(array, 0, (int)size - 1, size);
}
