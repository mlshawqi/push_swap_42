/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:08:42 by machaouk          #+#    #+#             */
/*   Updated: 2025/02/10 18:26:17 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - i - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_arr(t_data *data)
{
	t_stack	*lst;
	int		i;

	data->arr = malloc(data->size * sizeof(int));
	if (!data->arr)
		ft_clear_exit(data);
	lst = data->stack_a;
	i = 0;
	while (lst != NULL)
	{
		data->arr[i] = lst->number;
		lst = lst->next;
		i++;
	}
	ft_bubble_sort(data->arr, data->size);
}

void	ft_cmp_stack(t_data *data)
{
	int		i;
	t_stack	*lst;

	i = 0;
	lst = data->stack_a;
	while (lst != NULL)
	{
		if (lst->number == data->arr[i])
			i++;
		else
		{
			ft_printf("KO\n");
			ft_clear_exit(data);
		}
		lst = lst->next;
	}
	if (data->size_b == 0)
		ft_printf("OK\n");
	else
	{
		ft_printf("KO\n");
		ft_clear_exit(data);
	}
}
