/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:50:39 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:50:40 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stacks(t_data **d, int argc)
{
	*d = (t_data *)malloc(sizeof(t_data));
	(*d)->sorted_arr = (int *)malloc(sizeof(int) * (argc - 1));
	(*d)->a = NULL;
	(*d)->b = NULL;
	(*d)->ar_count = argc - 1;
	(*d)->op_count = 0;
}

void	fill_a(t_data *d, char **args, int argc)
{
	t_stack	*iter;
	int		i;

	d->a = (t_stack *)malloc(sizeof(t_stack));
	d->a->data = ft_atoi(args[1]);
	d->a->next = NULL;
	i = 2;
	iter = d->a;
	while (i <= argc - 1)
	{
		iter->next = (t_stack *)malloc(sizeof(t_stack));
		iter->next->data = ft_atoi(args[i]);
		iter->next->next = NULL;
		iter = iter->next;
		i++;
	}
}

void	push_swap(t_data *d)
{
	if (check_sorted(d->a))
		return ;
	if (d->ar_count == 3)
		case_three(d);
	else if (d->ar_count < 11)
		case_ten_sorting(d);
	else if (d->ar_count < 101)
		push_all_quarters(d, 4, 4);
	else
		push_all_quarters(d, 8, 8);
}

int	find_pivot(t_data *d, int quarter, int divider)
{
	return (d->sorted_arr[(d->ar_count * quarter) / divider]);
}
