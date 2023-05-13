/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_less_than_ten.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:39:44 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:43:18 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	case_three(t_data *d)
{
	if (d->a->data > d->a->next->data && d->a->data < d->a->next->next->data
		&& d->a->next->data < d->a->next->next->data)
		swap_a(d);
	else if (d->a->data > d->a->next->data
		&& d->a->data > d->a->next->next->data
		&& d->a->next->data > d->a->next->next->data)
	{
		swap_a(d);
		reverse_rotate_a(d);
	}
	else if (d->a->data > d->a->next->data
		&& d->a->data > d->a->next->next->data
		&& d->a->next->data < d->a->next->next->data)
		rotate_a(d);
	else if (d->a->data < d->a->next->data
		&& d->a->data < d->a->next->next->data
		&& d->a->next->data > d->a->next->next->data)
	{
		swap_a(d);
		rotate_a(d);
	}
	else
		reverse_rotate_a(d);
}

int	check_sorted(t_stack *s)
{
	t_stack	*iter;

	iter = s;
	while (iter->next)
	{
		if (iter->data > iter->next->data)
			return (0);
		iter = iter->next;
	}
	return (1);
}

void	case_ten(t_data *d)
{
	int	sm;
	int	proximity;
	int	index;

	sm = find_smallest(d->a);
	proximity = find_length(d->a) / 2;
	index = find_index(d->a, sm);
	while (d->a->data != sm)
	{
		if (proximity > index)
			rotate_a(d);
		else
			reverse_rotate_a(d);
	}
	push_b(d);
}

void	case_ten_sorting(t_data *d)
{
	while (find_length(d->a) > 3)
		case_ten(d);
	if (!check_sorted(d->a))
		case_three(d);
	while (find_length(d->a) < d->ar_count)
		push_a(d);
}
