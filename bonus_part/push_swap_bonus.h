/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:09:32 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:09:32 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
}					t_stack;

typedef struct s_dataa
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				size;
	int				size_b;
	int				*arr;
	int				chunk_size;
}					t_data;

void				ft_parsing(int ac, char **av, t_data *data_a);
int					ft_isnums(char *str);
int					count_strings(t_list *node, int len);
int					convert_strings(t_data *data, t_list *lst);
void				process_input(char **str, int ac, t_data *data);
int					ft_checkdupes(t_stack *stack_a);
int					is_sign(char *str, int i);

void				link_node(t_stack **head, int nbr);
t_stack				*ft_lstlast(t_stack *lst);
void				ft_lstadd_front(t_stack **lst, t_stack *new);

void				sa_swap(t_stack **data);
void				ra_rotate(t_stack **data);
void				rra_reverse_rotete(t_stack **data);
void				pa_push(t_data *data);
void				instructions(t_data *data, char hint);

void				sb_swap(t_stack **data);
void				rb_rotate(t_stack **data);
void				rrb_reverse_rotete(t_stack **data);
void				pb_push(t_data *data);

void				ft_read_ins(t_data *data);
int					is_valid(char *string, t_data *data);
void				ft_cmp_stack(t_data *data);
void				ft_sort_arr(t_data *data);

void				ft_clear_exit(t_data *data);
void				ft_exit(t_data *d);
void				ft_stack_clear(t_stack **lst);
void				ft_stack_delone(t_stack *lst);

#endif