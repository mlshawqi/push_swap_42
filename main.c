#include "push_swap.h"

void    ft_exit(t_data *d)
{
    write(1, "Error\n", ft_strlen("Error\n"));
    free(d->arr);
    exit (0);
}

int main(int argc, char *argv[])
{
    t_data  data;
    ft_parsing(argc, argv, &data);
    int i = 0;
    while(i < data.size)
    {
        printf("%d\n", data.arr[i]);
        i++;
    }
    free(data.arr);
    printf("nice\n");
}