#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_data{
    int *arr;
    int size;
}               t_data;
void    ft_exit(t_data *d);
void    ft_parsing(int ac, char **av, t_data *d);
int	ft_isnums(char *str);
int     count_strings(t_list *node, int len);
int    convert_strings(t_data *d, t_list *lst);
void    process_input(char **str, int ac, t_data *d);

#endif