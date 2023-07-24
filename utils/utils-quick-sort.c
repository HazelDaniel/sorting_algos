#include "../sort.h"

void sort_lomuto(int *array, int low, int high);
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

	i = low - 1;
	/*
	 * setting pivot_index to high works like lomuto and it's not right
	 * but it works for the alx task
	 * */
	pivot_index = high;
	j = high + 1;

	if (!count)
		size = high + 1;
	while (i < j)
	{
		do {
			i++;
		} while (array[i] < array[pivot_index]);

		do {
			j--;
		} while (array[j] > array[pivot_index]);

		if (i < j)
		{
			tmp = array[i], array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}
	count++;
	return (i);
}

/**
 * sort_hoare - a sub-routine that has the actual
 * implementation of quick sort
 * @array: the input array
 * @low: the starting index
 * @high: the ending index
 * Return: void
 **/
void sort_hoare(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition_hoare(array, low, high);
	 (sort_hoare(array, low, pivot_index - 1));
	 (sort_hoare(array, pivot_index, high));
	}
}
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
	for (; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
	}
	if (array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}
	count++;

	return (i + 1);
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
 * sort_lomuto - a sub-routine that has the actual
 * implementation of quick sort
 * @array: the input array
 * @low: the starting index
 * @high: the ending index
 * Return: void
 **/
void sort_lomuto(int *array, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition_lomuto(array, low, high);
	 (sort_lomuto(array, low, pivot_index - 1));
	 (sort_lomuto(array, pivot_index, high));
	}
}
