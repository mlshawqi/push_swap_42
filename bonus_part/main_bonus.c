#include "push_swap_bonus.h"

int main(int argc, char *argv[])
{
    t_data  data;

    data.stack_a = NULL;
    data.stack_b = NULL;
    data.arr = NULL;
    data.size = 0;
    data.size_b = 0;
    ft_parsing(argc, argv, &data);
    ft_read_is(&data);
    if(data.size < 6)
        ft_sort_small(&data);
    else
        sort_large(&data);
    ft_clear_exit(&data);
}