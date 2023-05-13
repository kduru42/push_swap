/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 02:00:29 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 02:00:42 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_data	*d;

	if (argc == 1)
		return (0);
	if (!check_int(argv) || !check_min_max_val(argv) || !check_dublicate(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	init_stacks(&d, argc);
	fill_a(d, argv, argc);
	sort_pivot(d);
	push_swap(d);
	ft_free(d);
	return (0);
}
