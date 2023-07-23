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
	static int size, count;

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
		}
	}
	tmp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = tmp;
	print_array(array, size);
	count++;

	return (i + 1);
}

/**
 * partition_hoare - a function that partitions
 * an array using hoare partitioning scheme
 * @array: the input array
 * @low: the starting index
 * @high: the last index
 * Return: int
 **/
int partition_hoare(int *array, int low, int high)
{
	int j, i, tmp, pivot_index;
	static int size, count;

	i = low;
	pivot_index = low;
	j = high + 1;

	if (!count)
		size = high + 1;
	while (i < j)
	{
		do {
			j--;
		} while (array[j] >= array[pivot_index]);

		do {
			i++;
		} while (array[i] < array[pivot_index]);

		if (i < j)
		{
			tmp = array[i], array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
		else
		{
			break;
		}
	}
	tmp = array[pivot_index], array[pivot_index] = array[j];
	array[j] = tmp;

	return (j);
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
	if (size <= 1)
		return;
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

/**
 * quick_sort_hoare - a function that sorts
 * an input array using quick sort algorithm
 * and a hoare partitioning scheme
 * @array: an input array
 * @low: the first element in the array
 * @high: the last element in the array
 * Return: void
 **/
void quick_sort_hoare(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition_hoare(array, low, high);
	 (quick_sort_hoare(array, low, pivot_index - 1));
	 (quick_sort_hoare(array, pivot_index + 1, high));
	}
}
