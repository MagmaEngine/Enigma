#include "enigma.h"
#include <string.h>

struct EDynarr {
	void *arr;
	size_t item_size;
	uint num_items;
	uint item_cap;
};

/**
 * e_dynarr_init
 *
 * Initialize and return a dynamic array with items of size item_size
 * and an initial capacity of item_cap
 */
EDynarr *e_dynarr_init(const size_t item_size, const uint item_cap)
{
	EDynarr *d = malloc(sizeof *d);
	d->item_size = item_size;
	d->num_items = 0;
	d->item_cap = (item_cap > 0) ? item_cap : 1;
	d->arr = malloc(item_size * item_cap);
	return d;
}

/**
 * e_dynarr_init_arr
 *
 * Initialize and return a dynamic array with items of size item_size
 * and an initial capacity of item_cap
 */
EDynarr *e_dynarr_init_arr(const size_t item_size, const uint num_items, const void * const arr)
{
	EDynarr *d = malloc(sizeof *d);
	d->item_size = item_size;
	d->num_items = num_items;
	d->item_cap = num_items;
	d->arr = malloc(item_size * num_items);
	memcpy(d->arr, arr, item_size*num_items);
	return d;
}

/**
 * e_dynarr_deinit
 *
 * uninitializes a dynamic array.
 * frees the memory associated with it.
 */
void e_dynarr_deinit(EDynarr * const d)
{
	if (d == NULL)
		return;
	if (d->arr != NULL)
			free(d->arr);
	free(d);
}

/**
 * e_dynarr_item_count
 *
 * Returns the number of items in the dynamic array
 */
uint e_dynarr_item_count(const EDynarr * const d)
{
	return d->num_items;
}

/**
 * e_dynarr_item_size
 *
 * Returns the capacity of the dynamic array
 */
size_t e_dynarr_item_size(const EDynarr * const d)
{
	return d->item_size;
}

/**
 * e_dynarr_get_arr
 *
 * Returns the array
 */
void *e_dynarr_get_arr(const EDynarr * const d)
{
	return d->arr;
}


/**
 * e_dynarr_add
 *
 * Adds an item to the dynamic array
 * reallocates more memory if needed
 */
void e_dynarr_add(EDynarr * const d, const void * const item)
{
	if (d->num_items >= d->item_cap)
	{
		d->item_cap *= 2;
		d->arr = realloc(d->arr, d->item_cap * d->item_size);
	}
	memcpy(&((char *)d->arr)[d->num_items++ * d->item_size], item, d->item_size);
}

/**
 * e_dynarr_append
 *
 * Appends one dynarr to another
 * reallocates more memory if needed
 */
void e_dynarr_append(EDynarr * const dest, const EDynarr * const src)
{
	if (dest->num_items + src->num_items >= dest->item_cap)
	{
		dest->item_cap *= 2;
		dest->arr = realloc(dest->arr, dest->item_cap * dest->item_size);
	}
	memcpy(&((char *)dest->arr)[dest->num_items * dest->item_size], src->arr, src->num_items * src->item_size);
	dest->num_items += src->num_items;
}

/**
 * e_dynarr_set
 *
 * Sets an item at index of the dynamic array
 * returns 1 if the set was out of bounds
 */
int e_dynarr_set(EDynarr * const d, const uint index, const void * const item)
{
	if (index >= d->num_items || index < 0)
		return 1;
	memcpy(&((char *)d->arr)[index * d->item_size], item, d->item_size);
	return 0;
}

/**
 * e_dynarr_remove_ordered
 *
 * remove an item at index
 * the order of the array is guaranteed to be preserved
 * returns 1 if the remove was out of bounds
 */
int e_dynarr_remove_ordered(EDynarr * const d, const uint index)
{
	if (index >= d->num_items) return 1;
	if (d->num_items-- > 1)
	{
		memmove(&((char *)d->arr)[index * d->item_size], &((char *)d->arr)[(index+1) * d->item_size],
			(d->num_items-index) * d->item_size);
		if (d->num_items < d->item_cap/2)
		{
			d->item_cap /= 2;
			d->arr = realloc(d->arr, d->item_cap * d->item_size);
		}
	}
	return 0;
}

/**
 * e_dynarr_remove_unordered
 *
 * remove an item at index
 * the order of the array is NOT guaranteed to be preserved
 * returns 1 if the remove was out of bounds
 */
int e_dynarr_remove_unordered(EDynarr * const d, const uint index)
{
	if (index >= d->num_items) return 1;
	if (d->num_items-- > 1)
	{
		memcpy(&((char *)d->arr)[index * d->item_size], &((char *)d->arr)[d->num_items * d->item_size], d->item_size);
		if (d->num_items < d->item_cap/2)
		{
			d->item_cap /= 2;
			d->arr = realloc(d->arr, d->item_cap * d->item_size);
		}
	}
	return 0;
}

/**
 * e_dynarr_find
 *
 * returns the index of the array that the item if it exists
 * if the array does not contain the item it returns -1
 */
int e_dynarr_find(const EDynarr * const d, const void * const item)
{
	for (uint i = 0; i < d->num_items; i++)
		if (memcmp(&((char *)d->arr)[i*d->item_size], item, d->item_size) == 0)
			return i;
	return -1;
}

/**
 * e_dynarr_remove_unordered_ptr
 *
 * finds an item in the array and removes it
 * the order of the array is NOT guaranteed to be preserved
 * returns 1 if the item does not exist in the array
 * or the remove could not be done
 */
int e_dynarr_remove_unordered_ptr(EDynarr * const d, const void * const item)
{
	for (uint i = 0; i < d->num_items; i++)
	{
		if (memcmp(&((char *)d->arr)[i*d->item_size], item, d->item_size) == 0)
		{
			return e_dynarr_remove_unordered(d, i);
		}
	}
	return 1;
}
