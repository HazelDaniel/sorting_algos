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

	while(y > 1)
	{
		x *= tmp;
		y--;
	}
	return (x);
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
	int prev_k_seq, count = size, x = 0, i, tmp;

	if (size <= 1)
		return;

	prev_k_seq = (power(3, size - 1) - 1) / 2;
	while (prev_k_seq >= count && count >= x)
		prev_k_seq = (power(3, count - (x++)) - 1) / 2;

	/* this should run logNbase3 times */
	while (prev_k_seq >= 1)
	{
		for (i = 0; (size_t)i < size; i++)
		{
			if ((size_t)(i + prev_k_seq) < size)
			{
				if (array[i + prev_k_seq] < array[i])
				{
					tmp = array[i];
					array[i] = array[i + prev_k_seq];
					array[i + prev_k_seq] = tmp;
					print_array(array, size);
				}
			}
			else
			{
				break;
			}
		}
		if (prev_k_seq == 1)
				break;
		prev_k_seq = (power(3, count - (x++)) - 1) / 2;
	}
	insertion_sort(array, size);
}
