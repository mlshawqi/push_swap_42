/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:07:30 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:07:30 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.stack_a = NULL;
	data.stack_b = NULL;
	data.arr = NULL;
	data.size = 0;
	data.size_b = 0;
	ft_parsing(argc, argv, &data);
	if (data.size < 6)
		ft_sort_small(&data);
	else
		sort_large(&data);
	ft_clear_exit(&data);
}
