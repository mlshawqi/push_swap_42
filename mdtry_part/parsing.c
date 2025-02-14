/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:08:08 by machaouk          #+#    #+#             */
/*   Updated: 2025/02/10 17:01:31 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnums(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+')
			&& ft_isdigit(str[i + 1]))
			i++;
		else if (ft_isdigit(str[i]) || ft_isspace(str[i]) || is_sign(str, i))
			i++;
		else
			return (0);
	}
	return (1);
}

int	ft_checkdupes(t_stack *stack_a)
{
	t_stack	*node;

	while (stack_a != NULL)
	{
		node = stack_a->next;
		while (node != NULL)
		{
			if (stack_a->number == node->number)
				return (1);
			node = node->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

int	ft_issort(t_stack *stack_a)
{
	int		min;
	t_stack	*node;

	while (stack_a != NULL)
	{
		node = stack_a->next;
		min = stack_a->number;
		while (node != NULL)
		{
			if (min > node->number)
				return (1);
			node = node->next;
		}
		stack_a = stack_a->next;
	}
	return (0);
}

void	ft_parsing(int ac, char **av, t_data *data_a)
{
	int	i;

	if (ac > 1)
	{
		i = 1;
		while (i < ac)
		{
			if (av[i][0] != '\0' && ft_isnums(av[i])
				&& (ft_isempty(av[i]) == 0))
				i++;
			else
				ft_exit(data_a);
		}
		process_input(av, ac, data_a);
		if (ft_checkdupes(data_a->stack_a))
			ft_exit(data_a);
		if (!ft_issort(data_a->stack_a))
			ft_clear_exit(data_a);
	}
	else
		exit(0);
}
