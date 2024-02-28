#include "push_swap.h"

#include <stdio.h>

void	print_range(t_range_info *r)
{
	int i = 0;

	while (i < r->size)
	{
		printf("| %d |", r->index_arr[i]);
		i++;
	}
	printf("\n");
}

int	cost_to_top(t_stack *stack, int index)
{
	int	i;
	int	size;

	size = stack_size(stack);
	i = 0;
	while (stack)
	{
		if (stack->index == index)
		{
			if (i < size / 2)
				return (i);
			else
				return (-(size - i));
		}
		i++;
		stack = stack->next;
	}
	return (0);
}

int	cheapest_in_range(t_pushswap *ps)
{
	int	i;
	int	tmp;
	int	cost;
	int	cheapest;

	cheapest = 2147483647;
	cost = 0;
	i = -1;
        while (++i < ps->r->size)
        {
                tmp = cost_to_top(ps->a, ps->r->index_arr[i]);
                if (tmp < 0)
                {
                        if (-tmp < cheapest)
                        {
                                cheapest = -tmp;
                                cost = tmp;
                        }
                }
                else if (tmp < cheapest)
                {
                        cheapest = tmp;
                        cost = tmp;
                }
        }
	return (cost);
}

void	make_moves(t_pushswap *ps, int cost)
{
	if (cost < 0)
	{
		while (cost++ < 0)
			rra(ps);
	}
	else if (cost > 0)
	{
		while (cost-- > 0)
			ra(ps);
	}
}

int	smallest_in_range(t_pushswap *ps)
{
	int	i;
	int	smallest;

	smallest = ps->r->index_arr[0];
	i = 0;
	while (ps->r->index_arr[i])
	{
		if (ps->r->index_arr[i] < smallest)
			smallest = ps->r->index_arr[i];
		i++;
	}
	return (smallest);
}

void	third_algorithm(t_pushswap *ps, int size)
{
	ps->range = set_range(size);

	int *sorted_arr = bubblesort(stack_to_array(ps->a), size);
	set_index(ps->a, sorted_arr, size);
	ps->r = start_range(ps, size);
	ps->smallest_index = smallest_in_range(ps);
	while (ps->a)
	{
		while (ps->r->size)
		{
			make_moves(ps, cheapest_in_range(ps));
			remove_from_range(ps);
			ps->r->size--;
			pb(ps);
			if (ps->b && ps->b->index < ps->smallest_index)
				rb(ps);
		}
		free(ps->r->index_arr);
		free(ps->r);
		ps->r = next_range(ps, sorted_arr, size);
	}
	pa(ps);
	pa(ps);
	pa(ps);
	while (ps->b)
	{
		set_target(ps);
		find_best_case(ps);
	}
}
