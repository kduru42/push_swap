/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_some_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:47:17 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:47:17 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	to_array(t_data *d)
{
	t_stack	*iter;
	int		i;

	i = 0;
	iter = d->a;
	while (i < d->ar_count)
	{
		d->sorted_arr[i] = iter->data;
		iter = iter->next;
		i++;
	}
}

void	sort_pivot(t_data *d)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	to_array(d);
	while (i <= d->ar_count - 1)
	{
		j = 1;
		while (j <= d->ar_count - i - 1)
		{
			if (d->sorted_arr[j] >= d->sorted_arr[j + 1])
			{
				temp = d->sorted_arr[j];
				d->sorted_arr[j] = d->sorted_arr[j + 1];
				d->sorted_arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	find_smallest(t_stack *s)
{
	t_stack	*iter;
	int		smallest;

	iter = s;
	smallest = iter->data;
	while (iter)
	{
		if (iter->data <= smallest)
			smallest = iter->data;
		iter = iter->next;
	}
	return (smallest);
}

int	find_index(t_stack *s, int data)
{
	t_stack	*iter;
	int		i;

	i = 0;
	iter = s;
	while (iter)
	{
		if (iter->data == data)
			return (i);
		iter = iter->next;
		i++;
	}
	return (0);
}
