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
 * part - part and get pivot of array
 * @arr: pointer to array
 * @start: index start
 * @end: index end
 * @size: size of array original
 * Return: pivot
 */

int part(int *arr, int start, int end, int size)
{
	int pivot = arr[end];
	int lt = start, rt = end;

	while (lt < rt)
	{
		while (arr[lt] < pivot)
			lt++;
		while (arr[rt] > pivot)
			rt--;
		swap_elements(&arr[rt], &arr[lt]);
		if (arr[lt] != arr[rt])
			print_array(arr, size);
	}
	return (rt);
}

/**
 * sorting - recursive function of sorting the new subarrays
 * @arr: pointer to array
 * @start: start index
 * @end: end index
 * @size: size of array
 * Return: nothing
 */

void sorting(int *arr, int start, int end, int size)
{
	int pivot;

	if (start < end)
	{
		pivot = part(arr, start, end, size);
		sorting(arr, start, pivot - 1, size);
		sorting(arr, pivot + 1, end, size);
	}
}

/**
 * quick_sort_hoare - quick sort hoare partition method
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	sorting(array, 0, size - 1, size);
}
