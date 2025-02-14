/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 11:33:30 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 11:33:30 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_large(t_data *data)
{
	ft_sort_arr(data);
	if (data->size >= 6 && data->size <= 15)
		data->chunk_size = 3;
	else if (data->size <= 100)
		data->chunk_size = 16;
	else if (data->size <= 500)
		data->chunk_size = 25;
	else
		data->chunk_size = 45;
	ft_stack_moves(data);
}
