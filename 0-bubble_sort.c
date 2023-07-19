#include "sort.h"

/**
 * bubble_sort - a function that sorts
 * an array using the bubble sort algorithm
 * @array: the input array
 * @size: the size of the input array
 * Return: void
 **/
void bubble_sort(int *array, size_t size)
{
	int i = 0, j = 0, tmp, swapped = 0;

	for (i = 0; (size_t)i < size - 1; i++)
	{
		for (j = size - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				tmp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = tmp;
				swapped = 1;
			}
		}
		if (!swapped) /* this is used to augment the best-case time complexity */
			break;
	}
}
