/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:51:31 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:58:27 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_smaller_than_pivot(t_data *d, int smaller)
{
	int	proximity;
	int	index;

	proximity = find_length(d->a) / 2;
	index = find_index(d->a, smaller);
	while (d->a->data != smaller)
	{
		if (proximity > index)
			rotate_a(d);
		else
			reverse_rotate_a(d);
	}
	push_b(d);
}

void	smaller_than_pivot(t_data *d, int quarter, int divider)
{
	t_stack	*iter;
	int		pivot;
	int		i;

	iter = d->a;
	pivot = find_pivot(d, quarter, divider);
	i = 0;
	while (i < d->ar_count / divider)
	{
		if (iter->data <= pivot)
		{
			push_smaller_than_pivot(d, iter->data);
			iter = d->a;
			i++;
		}
		else
			iter = iter->next;
	}
}

void	push_all_quarters(t_data *d, int quarter, int divider)
{
	int	proximity;
	int	biggest;
	int	index;

	push_quarters_to_b(d, quarter, divider);
	sort_last_of_a(d);
	while (find_length(d->b) > 1)
	{
		biggest = find_biggest(d);
		proximity = find_length(d->b) / 2;
		index = find_index(d->b, biggest);
		while (d->b->data != biggest)
		{
			if (d->b->next->data == biggest)
				swap_b(d);
			else if (proximity > index)
				rotate_b(d);
			else
				reverse_rotate_b(d);
		}
		push_a(d);
	}
	push_a(d);
}

int	find_biggest(t_data *d)
{
	t_stack	*iter;
	int		biggest;

	iter = d->b;
	biggest = iter->data;
	while (iter)
	{
		if (iter->data >= biggest)
			biggest = iter->data;
		iter = iter->next;
	}
	return (biggest);
}
