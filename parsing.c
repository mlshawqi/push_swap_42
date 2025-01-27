#include "push_swap.h"

int	ft_isnums(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        if (ft_isdigit(str[i]) || str[i] == ' ' 
            || ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1])))
            i++;
        else
            return (0);
    }
    return (1);
}

void    ft_checkdupes(t_data *tab)
{
    int i;
    int j;

    i = 0;
    while(i < tab->size)
    {
        j = i + 1;
        while(j < tab->size)
        {
            if(tab->stacka[i] == tab->stacka[j])
                ft_exit(tab, "There are duplicates of some arguments!");
            j++;
        }
        i++;
    }
}

int    ft_issort(t_data *tab)
{
    int i;
    int j;
    int min;

    i = 0;
    while(i < tab->size)
    {
        j = i + 1;
        min = tab->stacka[i];
        while(j < tab->size)
        {
            if(tab->stacka[j] < min)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void    ft_parsing(int ac, char **av, t_data *d)
{
    int i;

    if (ac > 1)
    {
        i = 1;
        while(i < ac)
        {
            if(ft_isnums(av[i]))
                i++;
            else
                ft_exit(d, "Some arguments are not integers!");
        }
        process_input(av, ac, d);
        ft_checkdupes(d);
        if(ft_issort(d))
        ft_exit(d, "Arguments already sorted!");
    }
    else
        ft_exit(d, "Need more arguments!");
}