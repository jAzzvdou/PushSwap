#include "push_swap.h"

#include <stdio.h>

int	set_range(int size)
{
	int	range;

	range = 1;
	if (size >= 500)
		range = 18;
	else if (size >= 100)
		range = 6;
	return (range);
}

t_range_info	*start_range(t_pushswap *ps, int size)
{
	t_range_info	*r;

	r = malloc(sizeof(t_range_info));
	r->start = ((size / 2)) - ps->range;
	r->end = ((size / 2) + (size % 2)) + (ps->range - 1);
	r->size = r->end - r->start + 1;
	r->index_arr = malloc(sizeof(int) * (r->end - r->start) + 1);
	int  ii = r->start;
	int i = 0;
	while (i <= r->end - r->start)
		r->index_arr[i++] = ii++;
	return (r);

}

void	remove_from_range(t_pushswap *ps)
{
	int	*new_r;

	new_r = malloc(sizeof(int) * (ps->r->size - 1));
	int ii = 0;
	int i = 0;
	while (i < ps->r->size)
	{
		if (ps->a && ps->r->index_arr[i] == ps->a->index)
			i++;
		else
			new_r[ii++] = ps->r->index_arr[i++];
	}
	free(ps->r->index_arr);
	ps->r->index_arr = new_r;
}

t_range_info	*next_range(t_pushswap *ps, int *sorted_arr, int size)
{
	t_range_info	*new_r;

	new_r = malloc(sizeof(t_range_info));
	new_r->start = ps->r->start - ps->range;
	if (new_r->start < 0)
		new_r->start = 0;
	new_r->end = ps->r->end + ps->range;
	if (new_r->end > size - 1)
		new_r->end = size - 1;
	new_r->size = ps->r->end - ps->r->start + 1;
	new_r->index_arr = malloc(sizeof(int) * (ps->r->end - ps->r->start) + 1);
	int i = new_r->start;
	int ii = 0;
	while (i < ps->r->start)
		new_r->index_arr[ii++] = sorted_arr[i++];
	i = new_r->end;
	int iii = ps->r->end;
	while (iii <= i)
		new_r->index_arr[ii++] = sorted_arr[iii++];
	free(ps->r);
	return (new_r);
}
