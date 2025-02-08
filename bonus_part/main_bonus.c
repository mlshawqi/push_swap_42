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
    ft_read_ins(&data);
    ft_sort_arr(&data);
    ft_cmp_stack(&data);
    // t_stack *node = data.stack_a;
    // while(node != NULL)
    // {
    //     printf(" stack a = %d\n", node->number);
    //     node = node->next;
    // }
    ft_clear_exit(&data);
}