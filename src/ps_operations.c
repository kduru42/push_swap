/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:49:44 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:49:51 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_data *d)
{
	t_stack	*iter;
	int		temp;

	if (!d->a || !d->a->next)
		return ;
	iter = d->a;
	temp = iter->data;
	iter->data = iter->next->data;
	iter->next->data = temp;
	ft_printf("sa\n");
	d->op_count++;
}

void	swap_b(t_data *d)
{
	t_stack	*iter;
	int		temp;

	if (!d->b || !d->b->next)
		return ;
	if (!(d->a->next))
	{
		d->a->next = d->b;
		d->b = d->a;
	}
	else
	{
		iter = d->b;
		temp = iter->data;
		iter->data = iter->next->data;
		iter->next->data = temp;
	}
	ft_printf("sb\n");
	d->op_count++;
}

void	swap_both(t_data *d)
{
	swap_a(d);
	swap_b(d);
	ft_printf("ss\n");
	d->op_count++;
}

void	push_a(t_data *d)
{
	t_stack	*temp;

	if (!(d->b))
		return ;
	if (!(d->b->next))
	{
		d->b->next = d->a;
		d->a = d->b;
	}
	else
	{
		temp = d->b;
		d->b = d->b->next;
		temp->next = d->a;
		d->a = temp;
	}
	ft_printf("pa\n");
	d->op_count++;
}
