#include "sort.h"

/**
 * counting_sort - sort array in ascending orders
 * using counting algorithm
 * @array: pointer to array
 * @size: size of array
 * Return: nothing
 */

void counting_sort(int *array, size_t size)
{
	int *output, *counting;
	size_t i, max;

	if (size < 2)
		return;
	max = array[0];
	for (i = 0; i < size; i++)
		if (array[i] > (int)max)
			max = array[i];
	counting = malloc(sizeof(int) * (max + 1));
	if (counting == NULL)
		return;
	for (i = 0; i < (max + 1); i++)
		counting[i] = 0;
	for (i = 0; i < size; i++)
		counting[array[i]] += 1;
	for (i = 1; i < (max + 1); i++)
		counting[i] += counting[i - 1];
	print_array(counting, max + 1);
	for (i = max + 1; i > 0; i--)
		counting[i] = counting[i - 1];
	counting[0] = 0;
	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(counting);
		return;
	}
	for (i = 0; i < size; i++)
	{
		output[counting[array[i]]] = array[i];
		counting[array[i]] += 1;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(counting);
	free(output);
}
