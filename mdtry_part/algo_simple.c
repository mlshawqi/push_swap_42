/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:07:10 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:07:10 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_data *data, int min, int max)
{
	if (min == data->stack_a->next->number
		&& max == data->stack_a->next->next->number)
		sa_swap(&data->stack_a);
	else if (min == data->stack_a->next->number && max == data->stack_a->number)
		ra_rotate(&data->stack_a);
	else if (min == data->stack_a->next->next->number
		&& max == data->stack_a->next->number)
		rra_reverse_rotete(&data->stack_a);
	else if (min == data->stack_a->next->next->number
		&& max == data->stack_a->number)
	{
		sa_swap(&data->stack_a);
		rra_reverse_rotete(&data->stack_a);
	}
	else if (min == data->stack_a->number && max == data->stack_a->next->number)
	{
		sa_swap(&data->stack_a);
		ra_rotate(&data->stack_a);
	}
}

void	ft_sort_main(t_data *data)
{
	int		min;
	int		max;
	t_stack	*node;

	min = data->stack_a->number;
	max = data->stack_a->number;
	node = data->stack_a;
	while (node != NULL)
	{
		if (node->number < min)
			min = node->number;
		else if (node->number > max)
			max = node->number;
		node = node->next;
	}
	ft_sort_3(data, min, max);
}

void	ft_loop_rotate_a(t_data *data, int pos)
{
	if (pos <= (data->size / 2))
	{
		while (pos > 0)
		{
			ra_rotate(&data->stack_a);
			pos--;
		}
	}
	else if (pos > (data->size / 2))
	{
		while (pos < data->size)
		{
			rra_reverse_rotete(&data->stack_a);
			pos++;
		}
	}
}

void	min_nbr(t_data *data)
{
	int		i;
	int		min;
	int		pos;
	t_stack	*node;

	min = data->stack_a->number;
	node = data->stack_a;
	i = 0;
	pos = -1;
	while (node != NULL)
	{
		if (node->number < min)
		{
			min = node->number;
			pos = i;
		}
		node = node->next;
		i++;
	}
	ft_loop_rotate_a(data, pos);
}

void	ft_sort_small(t_data *data)
{
	int	size;

	size = data->size;
	if (size == 3)
		ft_sort_main(data);
	else if (size == 2)
		sa_swap(&data->stack_a);
	else
	{
		min_nbr(data);
		pb_push(data);
		if (size == 5)
		{
			min_nbr(data);
			pb_push(data);
		}
		ft_sort_main(data);
		pa_push(data);
		if (size == 5)
			pa_push(data);
	}
}
