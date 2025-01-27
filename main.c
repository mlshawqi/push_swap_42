#include "push_swap.h"

void    ft_exit(t_data *d, char *msg)
{
    ft_printf("Error\n%s\n", msg);
    if(d->stacka)
        free(d->stacka);
    exit (0);
}

int main(int argc, char *argv[])
{
    t_data  data;
    ft_parsing(argc, argv, &data);
    int i = 0;
    while(i < data.size)
    {
        printf("%d\n", data.stacka[i]);
        i++;
    }
    free(data.stacka);
    printf("nice\n");
}