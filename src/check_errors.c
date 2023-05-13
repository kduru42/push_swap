/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 01:43:57 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 01:44:11 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_int(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] != '-')
				if (!ft_isdigit(args[i][j]))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_min_max_val(char **args)
{
	int		i;
	long	num;

	i = 1;
	while (args[i])
	{
		num = ft_atoi(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_dublicate(char **args)
{
	int	i;
	int	j;

	i = 1;
	while (args[i])
	{
		j = i + 1;
		while (args[j])
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free(t_data *d)
{
	t_stack	*iter;

	iter = d->a;
	while (iter)
	{
		free(iter);
		iter = iter->next;
	}
	free(d->sorted_arr);
	free(d);
}
