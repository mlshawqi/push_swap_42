/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:07:17 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:07:17 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_delone(t_stack *lst)
{
	if (lst == NULL)
		return ;
	free(lst);
}

void	ft_stack_clear(t_stack **lst)
{
	t_stack	*p;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_stack_delone(*lst);
		*lst = p;
	}
	*lst = NULL;
}

void	ft_clear_exit(t_data *data)
{
	if (data->stack_a)
		ft_stack_clear(&data->stack_a);
	if (data->stack_b)
		ft_stack_clear(&data->stack_b);
	if (data->arr)
		free(data->arr);
	exit(0);
}

void	ft_exit(t_data *d)
{
	write(2, "Error\n", 6);
	if (d->stack_a)
		ft_stack_clear(&d->stack_a);
	if (d->stack_b)
		ft_stack_clear(&d->stack_b);
	if (d->arr)
		free(d->arr);
	exit(0);
}
