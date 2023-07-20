#include "sort.h"

/**
 * partition_lomuto  - a function that partitions
 * an array for quick sort algorithm
 * using lomuto partitioning scheme
 * @array: the input array
 * @low: the first index in the array
 * @high: the last index in the array
 * Return: int
 **/
int partition_lomuto(int *array, int low, int high)
{
	int j = low, i = low - 1, pivot = array[high], tmp;
	static int size, count = 0;

	if (!count)
		size = high + 1;
	for (; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	count++;

	return (i + 1);
}
/**
 * quick_sort - a function that sorts an input array
 * using the quick sort algorithm
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void quick_sort(int *array, size_t size)
{
	(quick_sort_lomuto(array, 0, size - 1));
}

/**
 * quick_sort_lomuto - a function that sorts
 * an input array using quick sort algorithm
 * and a lomuto partitioning scheme
 * @array: an input array
 * @low: the first element in the array
 * @high: the last element in the array
 * Return: void
 **/
void quick_sort_lomuto(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition_lomuto(array, low, high);
	 (quick_sort_lomuto(array, low, pivot_index - 1));
	 (quick_sort_lomuto(array, pivot_index + 1, high));
	}
}
