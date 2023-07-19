#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly-linked
 * list using insertion sort
 * @list: the address of the doubly-linked list
 * Return: void
 **/
void insertion_sort_list(listint_t **list)
{
	int key;
	listint_t *prev, *curr, *curr_tmp, *prev_tmp, *print_prev,
	*tmp;

	if (!(*list) || !(*list)->next)
		return;

	for (curr = (*list)->next; curr; curr = curr->next)
	{
		prev = curr->prev;
		key = curr->n;

		while (prev && prev->n > key)
		{
			prev_tmp = prev, curr_tmp = prev->next;
			prev_tmp->next = curr_tmp->next;
			curr_tmp->next = prev_tmp;
			if (prev_tmp->prev)
				prev_tmp->prev->next = curr_tmp;
			if (prev_tmp->next)
				prev_tmp->next->prev = prev_tmp;
			curr_tmp->prev = prev_tmp->prev;
			prev = prev_tmp->prev;
			prev_tmp->prev = curr_tmp;
			print_prev = prev_tmp;
			while (print_prev)
				tmp = print_prev, print_prev = print_prev->prev;
			print_list(tmp);
		}
	}
	*list = tmp;
}
