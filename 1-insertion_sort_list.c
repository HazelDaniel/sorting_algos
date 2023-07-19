#include "sort.h"

typedef struct {
	int *items;
	int size;
} dll_array_t;

/**
 * extract_array - a function that extracts an array
 * from a doubly-linked list
 * @list: the doubly-linked list
 * Return: dll_array_t *
 **/
dll_array_t *extract_array(listint_t *list)
{
	listint_t *current = list;
	int *res = NULL, i = 0;
	dll_array_t *res_ptr = NULL;

	while (current)
	{
		current = current->next;
		res = realloc(res, i + 1);
		res[i++] = current->n;
	}
	if (list)
	{
		res_ptr = (dll_array_t *)malloc(sizeof(dll_array_t));
		res_ptr->size = i;
		res_ptr->items = res;
	}
	return (res_ptr);
}


/**
 * insertion_sort_list - a function that sorts a doubly-linked
 * list using insertion sort
 * @list: the address of the doubly-linked list
 * Return: void
 **/
void insertion_sort_list(listint_t **list)
{
	int i, j, tmp, key;
	dll_array_t *sort_arr = NULL;
	listint_t *current = *list;

	sort_arr = extract_array(*list);
	for (j = 1; j < sort_arr->size; j--)
	{
		i = j - 1;
		key = sort_arr->items[j];

		while (i > -1 && sort_arr->items[i] > key)
		{
			sort_arr->items[i + 1] = sort_arr->items[i];
			i--;
			sort_arr->items[i + 1] = key;
		}
	}

	while (current)
	{
		current->n = sort_arr->items[i++];
		current = current->next;
	}

}
