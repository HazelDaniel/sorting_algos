#include "sort.h"
#include "utils.c"


/**
 * counting_sort - a function that sorts an input array
 * using a non-comparation sorting algotithm called
 * counting sort
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void counting_sort(int *array, size_t size)
{
	int i, j, high, *result = NULL, *counts = NULL;

	high = find_max(array, size);
	/*
	 * below is  to make sure that the property of counting sort
	 * algorithm holds true prior to the iteration
	 * - the INT_MIN is returned if a negative value is found
	 *   in the array
	 */
	if (high == INT_MIN || size <= 1)
		return;
	counts = calloc(high + 1, sizeof(int));
	result = calloc(size, sizeof(int));

	for (i = 0; (size_t)i < size; i++)
	{
		printf("%d, ", counts[array[i]]);
		counts[array[i]] += 1;
	}

	for (i = 0; i <= high; i++)
	{
		if (i > 0)
			counts[i] += counts[i - 1];
	}

	for (j = 0; (size_t)j < size; j++)
	{
		result[counts[array[j]] - 1] = array[j];
		counts[array[j]] -= 1;
	}

	for (i = 0; (size_t)i < size; i++)
		array[i] = result[i];
}
