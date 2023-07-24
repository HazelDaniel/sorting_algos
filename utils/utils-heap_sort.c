#include "../sort.h"

/**
 * parent - a procedure used to compute the parent
 * of a an item in a sub-heap rooted at index i
 * in the array
 * @i: the array index of the current item in the heap
 * Return: int
 **/
int parent(int i)
{
	return (((i + 1) >> 1) - 1);
}

/**
 * left_child - a procedure that returns the left
 * child of an item in a sub-heap rooted at index i
 * in the array
 * @i: the array index of the current item in the heap
 * Return: int
 **/
int left_child(int i)
{
	return ((i << 1) + 1);
}

/**
 * left_child - a procedure that returns the right
 * child of an item in a sub-heap rooted at index i
 * in the array
 * @i: the array index of the current item in the heap
 * Return: int
 **/
int right_child(int i)
{
	return ((i << 1) + 2);
}
