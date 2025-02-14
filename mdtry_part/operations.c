/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:08:01 by machaouk          #+#    #+#             */
/*   Updated: 2025/02/10 11:27:13 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_swap(t_stack **data)
{
	t_stack	*tmp;

	if (!data || !(*data) || !(*data)->next)
		return ;
	tmp = *data;
	*data = (*data)->next;
	tmp->next = (*data)->next;
	(*data)->next = tmp;
	ft_printf("sa\n");
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
	ft_printf("ra\n");
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
	ft_printf("rra\n");
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
	ft_printf("pa\n");
}
