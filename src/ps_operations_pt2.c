/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_pt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:48:35 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:48:36 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_b(t_data *d)
{
	t_stack	*temp;

	if (!(d->a))
		return ;
	if (!(d->a->next))
	{
		d->a->next = d->b;
		d->b = d->a;
	}
	else
	{
		temp = d->a;
		d->a = d->a->next;
		temp->next = d->b;
		d->b = temp;
	}
	ft_printf("pb\n");
	d->op_count++;
}

void	rotate_a(t_data *d)
{
	t_stack	*temp;
	t_stack	*iter;

	if (!(d->a) || !(d->a->next))
		return ;
	iter = d->a;
	temp = d->a->next;
	while (iter->next)
		iter = iter->next;
	iter->next = d->a;
	d->a->next = NULL;
	d->a = temp;
	ft_printf("ra\n");
	d->op_count++;
}

void	rotate_b(t_data *d)
{
	t_stack	*temp;
	t_stack	*iter;

	if (!(d->b) || !(d->b->next))
		return ;
	iter = d->b;
	temp = d->b->next;
	while (iter->next)
		iter = iter->next;
	iter->next = d->b;
	d->b->next = NULL;
	d->b = temp;
	ft_printf("rb\n");
	d->op_count++;
}

void	rotate_both(t_data *d)
{
	rotate_a(d);
	rotate_b(d);
	ft_printf("rr\n");
	d->op_count++;
}
