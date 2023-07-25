#include "sort.h"

/**
 * swap - a function that swaps the content
 * of the addresses of two objects
 * @a: te address of the left object
 * @b: the address of the right object
 * Return: void
 **/
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * shell_sort - a function that sorts
 * an array using the shell sort algorithm
 * (Knuth sequence)
 * @array: the input array
 * @size: the size of the input array
 * Return: void
 **/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i;
	int j;

	if (!array || size <= 1)
		return;

	gap = (3 * gap) + 1;

	while (gap)
	{
		for (i = 0; i + gap < size; i++)
		{
			if (array[i] > array[i + gap])
			{
				swap(&array[i], &array[i + gap]);
				for (j = i; j >= 0 && array[j] < array[j - 1]; j--)
					swap(&array[j], &array[j - 1]);
			}
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
