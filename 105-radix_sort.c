#include "sort.h"

/**
 * counting - sort significant digit using counting
 * sort algorithm
 * @arr: pointer to array
 * @size: size f array
 * @place: which significant number we sort
 * Return: nothing
 */

void counting(int *arr, int size, int place)
{
	int *output, *count, i, max = 0;

	for (i = 0; i < size; i++)
	{
		if ((arr[i] / place) % 10 > max)
			max = (arr[i] / place) % 10;
	}
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i < max; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(arr[i] / place) % 10] += 1;
	for (i = 1; i < max; i++)
		count[i] += count[i - 1];
	for (i = max; i > 0; i--)
		count[i] = count[i - 1];
	count[0] = 0;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[count[(arr[i] / place) % 10]] = arr[i];
		count[(arr[i] / place) % 10] += 1;
	}
	for (i = 0; i < size; i++)
		arr[i] = output[i];
	free(count);
	free(output);
}

/**
 * radix_sort - sort array in ascending order
 * using radix sort algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void radix_sort(int *array, size_t size)
{
	int i, place = 1, max;

	if (size < 2)
		return;
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	for (i = max; i / place > 0; place *= 10)
	{
		counting(array, (int)size, place);
		print_array(array, size);
	}
}
