/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations_pt3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:49:29 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:49:29 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reverse_rotate_a(t_data *d)
{
	t_stack	*iter;
	t_stack	*temp;

	if (!d->a || !d->a->next)
		return ;
	iter = d->a;
	while (iter->next->next)
		iter = iter->next;
	temp = iter->next;
	iter->next = NULL;
	temp->next = d->a;
	d->a = temp;
	ft_printf("rra\n");
	d->op_count++;
}

void	reverse_rotate_b(t_data *d)
{
	t_stack	*iter;
	t_stack	*temp;

	if (!d->b || !d->b->next)
		return ;
	iter = d->b;
	while (iter->next->next)
		iter = iter->next;
	temp = iter->next;
	iter->next = NULL;
	temp->next = d->b;
	d->b = temp;
	ft_printf("rrb\n");
	d->op_count++;
}

void	reverse_rotate_both(t_data *d)
{
	reverse_rotate_a(d);
	reverse_rotate_b(d);
	ft_printf("rrr\n");
	d->op_count++;
}

int	find_length(t_stack *s)
{
	t_stack	*iter;
	int		i;

	i = 0;
	iter = s;
	while (iter)
	{
		i++;
		iter = iter->next;
	}
	return (i);
}
