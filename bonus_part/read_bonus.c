/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:09:38 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:09:38 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_valid(char *string, t_data *data)
{
	if (ft_strcmp(string, "sa\n") == 0)
		sa_swap(&data->stack_a);
	else if (ft_strcmp(string, "sb\n") == 0)
		sb_swap(&data->stack_b);
	else if (ft_strcmp(string, "ss\n") == 0)
		instructions(data, 's');
	else if (ft_strcmp(string, "ra\n") == 0)
		ra_rotate(&data->stack_a);
	else if (ft_strcmp(string, "rra\n") == 0)
		rra_reverse_rotete(&data->stack_a);
	else if (ft_strcmp(string, "pa\n") == 0)
		pa_push(data);
	else if (ft_strcmp(string, "rb\n") == 0)
		rb_rotate(&data->stack_b);
	else if (ft_strcmp(string, "rrb\n") == 0)
		rrb_reverse_rotete(&data->stack_b);
	else if (ft_strcmp(string, "pb\n") == 0)
		pb_push(data);
	else if (ft_strcmp(string, "rr\n") == 0)
		instructions(data, 'r');
	else if (ft_strcmp(string, "rrr\n") == 0)
		instructions(data, 'e');
	else
		return (1);
	return (0);
}

void	ft_read_ins(t_data *data)
{
	char	*string;

	string = get_next_line(0);
	while (string != NULL)
	{
		if (is_valid(string, data) == 1)
		{
			free(string);
			ft_printf("Error\n");
			ft_clear_exit(data);
		}
		free(string);
		string = get_next_line(0);
	}
}
