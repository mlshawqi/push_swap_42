#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*p;

	if (lst == NULL || *lst == NULL)
		return ;
	while (*lst != NULL)
	{
		p = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = p;
	}
	*lst = NULL;
}