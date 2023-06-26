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
 * bitonic_sort - sort array in ascending order using bitonic
 * sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void bitonic_sort(int *array, size_t size)
{
	if (size < 2)
		return;
}
