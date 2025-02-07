#include "push_swap_bonus.h"

void    ft_read_ins(t_data *data)
{
    char    *string;

    string = get_next_line(0);
    while(string != NULL)
    {
        if(ft_strcmp(string, "sa\n") == 0)
        sa_swap(&data->stack_a);
        else if (ft_strcmp(string, "ra\n") == 0)
        ra_rotate(&data->stack_a);
        else if (ft_strcmp(string, "rra\n") == 0)
            rra_reverse_rotete(&data->stack_a);
        else if (ft_strcmp(string, "pa\n") == 0)
            pa_push(data);
        else if (ft_strcmp(string, "rb\n") == 0)
            rb_rotate(&data->stack_b);
        else if (ft_strcmp(string, "rrb\n") == 0)
            rrb_reverse_rotete(&data->stack_b);
        else if (ft_strcmp(string, "pb\n") == 0)
            pb_push(data);
        else
        {
            ft_printf("KO\n");
            ft_clear_exit(data);
        }
        free(string);
        string = get_next_line(0);
    }
}
