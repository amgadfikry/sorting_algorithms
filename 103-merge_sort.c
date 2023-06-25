#include "sort.h"

/**
 * print_subarray - print sub array
 * @array: pointer to array
 * @start: start index
 * @end: end index
 * Return: nothing
 */

void print_subarray(int *array, int start, int end)
{
	int i = start;

	while (array && i < end)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		i++;
	}
	printf("\n");
}

/**
 * merge - compare two subarray and add them to output
 * array then replace with original array
 * @array: pointer to original array
 * @output: pointer to output array
 * @start: start index
 * @mid: split index to subarray
 * @end: end index of array
 * Return: nothing
 */

void merge(int *array, int *output, int start, int mid, int end)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array, start, mid);
	printf("[right]: ");
	print_subarray(array, mid, end);
	k = i = start;
	j = mid;
	while (i < mid && j < end)
	{
		if (array[i] < array[j])
		{
			output[k] = array[i];
			i++;
		}
		else
		{
			output[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		output[k] = array[i];
		i++;
		k++;
	}
	while (j < end)
	{
		output[k] = array[j];
		j++;
		k++;
	}
	for (i = start; i < end; i++)
		array[i] = output[i];
	printf("[Done]: ");
	print_subarray(array, start, end);
}

/**
 * merge_sorting - split array to two subarray
 * @array: original array pointer
 * @output:output array pointer
 * @start: start index
 * @end: end index
 * Return: nothing
 */

void merge_sorting(int *array, int *output, int start, int end)
{
	int mid;

	if (end - start > 1)
	{
		mid = (start + end) / 2;
		merge_sorting(array, output, start, mid);
		merge_sorting(array, output, mid, end);
		merge(array, output, start, mid, end);
	}
}

/**
 * merge_sort - sort array in ascending order
 * using merge sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void merge_sort(int *array, size_t size)
{
	int *output;

	if (size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	merge_sorting(array, output, 0, (int)size);
	free(output);
}
