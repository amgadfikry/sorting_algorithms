#include "sort.h"

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
	int index = start - 1, i, key = array[end], temp;

	for (i = start; i < end; i++)
	{
		if (array[i] <= key)
		{
			index++;
			if (i != index)
			{
				temp = array[i];
				array[i] = array[index];
				array[index] = temp;
				print_array(array, size);
			}
		}
	}
	if (index + 1 != end)
	{
		temp = array[end];
		array[end] = array[index + 1];
		array[index + 1] = temp;
		print_array(array, size);
	}
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
