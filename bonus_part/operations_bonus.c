/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:09:02 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:09:02 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_swap(t_stack **data)
{
	t_stack	*tmp;

	if (!data || !(*data) || !(*data)->next)
		return ;
	tmp = *data;
	*data = (*data)->next;
	tmp->next = (*data)->next;
	(*data)->next = tmp;
}

void	ra_rotate(t_stack **data)
{
	t_stack	*last_node;
	t_stack	*head;

	if (!data || !(*data) || !(*data)->next)
		return ;
	head = (*data)->next;
	last_node = ft_lstlast(*data);
	last_node->next = *data;
	*data = head;
	last_node->next->next = NULL;
}

void	rra_reverse_rotete(t_stack **data)
{
	t_stack	*prev;
	t_stack	*last_node;

	if (!data || !(*data) || !(*data)->next)
		return ;
	prev = NULL;
	last_node = *data;
	while (last_node->next)
	{
		prev = last_node;
		last_node = last_node->next;
	}
	prev->next = NULL;
	last_node->next = *data;
	*data = last_node;
}

void	pa_push(t_data *data)
{
	t_stack	*first_node;

	if (!data || !data->stack_b)
		return ;
	first_node = data->stack_b;
	data->stack_b = data->stack_b->next;
	first_node->next = NULL;
	ft_lstadd_front(&data->stack_a, first_node);
	data->size++;
	data->size_b--;
}

void	instructions(t_data *data, char hint)
{
	if (hint == 's')
	{
		sa_swap(&data->stack_a);
		sb_swap(&data->stack_b);
	}
	else if (hint == 'r')
	{
		ra_rotate(&data->stack_a);
		rb_rotate(&data->stack_b);
	}
	else if (hint == 'e')
	{
		rra_reverse_rotete(&data->stack_a);
		rrb_reverse_rotete(&data->stack_b);
	}
}
