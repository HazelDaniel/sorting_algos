#include "sort.h"
#include <limits.h>
/**
 * selection_sort - a function that sorts an array
 * based on the selection sort algorithm
 * @array: the input array to be sorted
 * @size: the size of the input array
 * Return: void
 **/
void selection_sort(int *array, size_t size)
{
	int i, j, tmp, minimum, min_index;

	if (size <= 1)
		return;
	for (i = 0; (size_t)i < size - 1; i++)
	{
		minimum = array[i];
		for (j = i + 1; (size_t)j < size; j++)
		{
			if (array[j] < minimum)
			{
				minimum = array[j];
				min_index = j;
			}
		}
		if (minimum != array[i])
		{
			tmp = array[i];
			array[i] = minimum;
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}
