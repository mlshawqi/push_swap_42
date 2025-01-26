#include "libft.h"

// void	ft_lstadd_back(t_list *lst, char **new)
// {
// 	t_list	*tp;

// 	if (!lst || !new)
// 		return ;
// 	if (*lst == NULL)
// 		*lst = new;
// 	else
// 	{
// 		tp = ft_lstlast(*lst);
// 		tp->next = new;
// 	}
// }

void    add_node(t_list **head, char **arr)
{
    t_list *new_node;
    t_list  *current;
    
    new_node = malloc(sizeof(t_list));
    if (!new_node) {
        return;
    }
    new_node->arr = arr;
    new_node->next = NULL;

    if (*head == NULL)
        *head = new_node;
    else
    {
        current = *head;
        while (current->next)
            current = current->next;
        current->next = new_node;
    }
}
