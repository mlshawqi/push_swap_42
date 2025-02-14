/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:08:54 by machaouk          #+#    #+#             */
/*   Updated: 2025/02/10 11:32:25 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	data.arr = NULL;
	data.size = 0;
	data.size_b = 0;
	ft_parsing(argc, argv, &data);
	ft_read_ins(&data);
	ft_sort_arr(&data);
	ft_cmp_stack(&data);
	ft_clear_exit(&data);
}
