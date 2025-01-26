#include "libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst == NULL)
		return ;
	del(lst->arr);
	free(lst);
}

void del(char **t)
{
    int i;

    i = 0;
    if (!t)
        return;
    while (t[i] != NULL)
    {
        free(t[i]);
        i++;
    }
    free(t);
}