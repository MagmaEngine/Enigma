#include "enigma.h"
#include <string.h>

dynarr *e_dynarr_init(size_t item_size, uint item_cap)
{
	dynarr *d = malloc(sizeof *d);
	d->item_size = item_size;
	d->num_items = 0;
	d->item_cap = item_cap;
	d->arr = malloc(item_size * item_cap);
	return d;
}

void e_dynarr_deinit(dynarr *d)
{
	if(d == NULL)
		return;
	if(d->arr != NULL)
			free(d->arr);
	free(d);
}

void e_dynarr_add(dynarr *d, void *item)
{
	if(d->num_items >= d->item_cap)
	{
		d->item_cap *= 2;
		d->arr = realloc(d->arr, d->item_cap * d->item_size);
	}
	memcpy(&((char *)d->arr)[d->num_items*d->item_size], item, d->item_size);
	d->num_items++;
}
