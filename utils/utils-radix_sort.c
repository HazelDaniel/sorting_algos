#include "../sort.h"
/**
 * create_rad_bin - a function that creates an array
 * of radix bins.
 * @size: the number of bins
 * Return: rad_bin_t *
 **/
rad_bin_t *create_rad_bin(int size)
{
	rad_bin_t *new_rbin;

	new_rbin = (rad_bin_t *)malloc(size * sizeof(rad_bin_t));

	if (!new_rbin)
		return (NULL);

	new_rbin->size = size;
	new_rbin->bins = (bin_list_t **)calloc(size, sizeof(bin_list_t *));

	if (!new_rbin->bins)
	{
		free(new_rbin);
		new_rbin = NULL;
	}

	return (new_rbin);
}

/**
 * reset_rad_bin - a function that re-initializes the items
 * of a rad_bin_t to NULL.
 * @r_bin: the array of bins
 * Return: void
 **/
void reset_rad_bin(rad_bin_t *r_bin)
{
	int i;
	bin_list_t *current = NULL, *tmp = NULL;

	if (!r_bin)
		return;

	for (i = 0; i < r_bin->size; i++)
	{
		if (r_bin->bins[i])
		{
			current = r_bin->bins[i];

			while (current)
			{
				tmp = current;
				current = current->next;
				free(tmp);
			}
			r_bin->bins[i] = NULL;
		}
	}
}

/**
 * free_rad_bin - a function that frees up the space
 * used by an array of radix bins
 * @r_bin: the address of the array
 * Return: void
 **/
void free_rad_bin(rad_bin_t **r_bin)
{
	int i;
	bin_list_t *current, *tmp;

	if (!(*r_bin))
		return;

	for (i = 0; i < (*r_bin)->size; i++)
	{
		if ((*r_bin)->bins[i])
		{
			current = (*r_bin)->bins[i];
			while (current)
			{
				tmp = current;
				current = current->next;
				free(tmp);
			}
			(*r_bin)->bins[i] = NULL;
		}
	}
	free((*r_bin)->bins);
	free(*r_bin), *r_bin = NULL;
}
