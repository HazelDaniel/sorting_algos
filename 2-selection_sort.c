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
	int i, j, tmp;

	for (i = 0; (size_t)i < size - 1; i++)
	{
		for (j = i + 1; (size_t)j < size; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				if (j + 1 == (int)size)
					print_array(array, size);
			}
		}
	}
}
