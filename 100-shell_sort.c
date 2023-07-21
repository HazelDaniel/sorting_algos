#include "sort.h"

/**
 * insertion_sort - a function that sorts an input array
 * based on the insertion sort algorithm
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void insertion_sort(int *array, size_t size)
{
	int i, j, key;

	for (j = 1; (size_t)j < size; j++)
	{
		key = array[j];
		i = j - 1;

		while ((int)i >= 0 && array[i] > key)
		{
			array[i + 1] = array[i];
			i--;
			array[i + 1] = key;
		}
	}
}

/**
 * power - a function that returns an operation
 * x ^ y on two input values x and y
 * @x: the first input value
 * @y: the second input value
 * Return: unsigned int
 **/
unsigned int power(unsigned int x, unsigned int y)
{
	unsigned int tmp = x;

	while (y > 1)
	{
		x *= tmp;
		y--;
	}
	return (x);
}

/**
 * fill_ptr - a function that dynamically adds an item
 * to a contiguous block. if the block is not already created
 * it creates it
 * @ptr: the address of the contiguous block
 * @item: the item to add
 * @size: the new size of the contiguous block
 * Return: void
 **/
void fill_ptr(void **ptr, int item, int size)
{
	int *ptr_store;

	if (!*ptr)
		*ptr = malloc(sizeof(int));
	else
		*ptr = realloc(*ptr, size);
	ptr_store = (int *)*ptr;
	(ptr_store)[size - 1] = item;
}

/**
 * shell_sort - a function that sorts an input array
 * based on the shell sort algorithm
 * @array: the input array
 * @size: the size of the input array - N
 * Return: void
 **/
void shell_sort(int *array, size_t size)
{
	int interval, i, j, tmp, count = 0,
	*items = NULL, *indices = NULL, s, new_interval;

	if (size <= 1)
		return;
	for (interval = 0; (size_t)interval <= (size - 1) / 3; )
		interval = interval * 3 + 1;
	while (interval >= 1)
	{
		count = 0;
		if (interval == 1)
			new_interval = interval + 1;
		else
			new_interval = interval;
		for (i = 0; (size_t)i < size && (size_t)(i + new_interval) < size; i++)
		{
			j = i, s = 0;
			while ((size_t)(j) < size)
			{
				s++;
				fill_ptr((void **)&indices, j, s);
				fill_ptr((void **)&items, array[j], s);
				j += new_interval, count++;
			}
			insertion_sort(items, s);
			for (tmp = 0; tmp < s; tmp++)
				array[indices[tmp]] = items[tmp];
			free(items), free(indices), items = indices = 0;
			if ((size_t)count >= size)
			{
				break;
			}
		}
		if (interval == 1)
			break;
		print_array(array, size);
		interval = ((interval - 1) / 3);
	}
	insertion_sort(array, size);
	print_array(array, size);
}
