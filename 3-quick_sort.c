#include "sort.h"
#include "utils/utils-quick-sort.c"
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
	(quick_sort_hoare(array, size));
}

/**
 * quick_sort_hoare - a function that sorts
 * an input array using quick sort algorithm
 * and a hoare partitioning scheme
 * @array: an input array
 * @size: the size of the array - N
 * Return: void
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (size > 1)
		sort_hoare(array, 0, size - 1);
}
