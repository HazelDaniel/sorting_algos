#include "sort.h"
#include "utils/utils-quick-sort.c"


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
		sort_lomuto(array, 0, size - 1);
}
