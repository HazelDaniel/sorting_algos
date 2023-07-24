#include "../sort.h"

/**
 *_calloc - this is a calloc function
 *@nmemb: number of elemets
 *@size: bit size of each element
 *Return: pointer to memory assignement
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		p[i] = 0;
	return (p);
}

/**
 * _fr_ptr - does the 'free' opertion
 * on a pointer and sets it to NULL
 * @ptr: the address of the pointer
 * Return: void
 **/
void _fr_ptr(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}
