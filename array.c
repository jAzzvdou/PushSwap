/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jazevedo <jazevedo@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:42:42 by jazevedo          #+#    #+#             */
/*   Updated: 2024/03/18 11:28:32 by jazevedo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*argv_to_array(char **argv, int size)
{
	int	i;
	int	*array;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
	return (array);
}

int	*bubblesort(int *array, int size)
{
	int	i;
	int	ii;
	int	tmp;

	i = -1;
	while (++i < size)
	{
		ii = i;
		while (++ii < size)
		{
			if (array[i] > array[ii])
			{
				tmp = array[i];
				array[i] = array[ii];
				array[ii] = tmp;
			}
		}
	}
	return (array);
}

void	set_index(t_node *node, int *sorted, int size)
{
	int	i;

	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (node->value == sorted[i])
				node->index = i;
			i++;
		}
		node = node->prev;
	}
}
