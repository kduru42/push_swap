/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kduru <kduru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:37:16 by kduru             #+#    #+#             */
/*   Updated: 2023/05/12 02:02:18 by kduru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct Stack	t_stack;

typedef struct Stack
{
	t_stack	*next;
	int		data;
}	t_stack;

typedef struct Data
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted_arr;
	int		ar_count;
	int		op_count;
	int		smallest_index;
}	t_data;

long	ft_atoi(const char *str);
void	init_stacks(t_data **d, int argc);
void	fill_a(t_data *d, char **args, int argc);
void	swap_a(t_data *d);
void	swap_b(t_data *d);
void	swap_both(t_data *d);
void	push_a(t_data *d);
void	push_b(t_data *d);
void	rotate_a(t_data *d);
void	rotate_b(t_data *d);
void	rotate_both(t_data *d);
void	reverse_rotate_a(t_data *d);
void	reverse_rotate_b(t_data *d);
void	reverse_rotate_both(t_data *d);
void	to_array(t_data *d);
void	case_three(t_data *d);
void	case_ten(t_data *d);
void	case_ten_sorting(t_data *d);
void	smaller_than_pivot(t_data *d, int quarter, int divider);
void	push_smaller_than_pivot(t_data *d, int smaller);
void	finally_sorted(t_data *d);
void	push_all_quarters(t_data *d, int quarter, int divider);
void	push_swap(t_data *d);
void	sort_pivot(t_data *d);
void	ft_free(t_data *d);
void	sort_last_of_a(t_data *d);
void	push_quarters_to_b(t_data *d, int quarter, int divider);
int		ft_isdigit(int c);
int		find_pivot(t_data *d, int quarter, int divider);
int		find_smallest(t_stack *s);
int		find_index(t_stack *s, int data);
int		find_length(t_stack *s);
int		check_sorted(t_stack *s);
int		find_biggest(t_data *d);
int		check_int(char **args);
int		check_min_max_val(char **args);
int		check_dublicate(char **args);

#endif