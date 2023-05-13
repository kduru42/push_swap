/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:57:58 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:58:10 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_last_of_a(t_data *d)
{
	while (find_length(d->a) > 3)
		case_ten(d);
	if (!check_sorted(d->a))
		case_three(d);
	while (find_length(d->a) < 24)
		push_a(d);
}

void	push_quarters_to_b(t_data *d, int quarter, int divider)
{
	int	i;

	i = 1;
	while (i <= quarter - 1)
	{
		smaller_than_pivot(d, i, divider);
		i++;
	}
}
