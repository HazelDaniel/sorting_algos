#include "sort.h"
#include <limits.h>

/**
 * find_max - a function that returns
 * the maximum item in an array
 * @array: the input array
 * @size: the size of the input array
 * Return: the maximum of the array
 * Description: this is customized for the
 * .................counting sort algorithm
 **/
int find_max(int *array, size_t size)
{
	int max = INT_MIN, i;

	if (!array)
		return (max);

	for (i = 0; (size_t)i < size; i++)
	{
		if (array[i] < 0)
			return (INT_MIN);
		if (array[i] > max)
			max = array[i];
	}

	return (max);
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
 * num_digits - returns the number of digits
 * in an input integer
 * @x: the input integer
 * Return: int
 **/
int num_digits(unsigned int x)
{
	int num = 0;

	if (!x)
		return (1);

	while (x)
	{
		x /= 10;
		num++;
	}

	return (num);
}
