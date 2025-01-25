#include <stdio.h>

void    ft_string(char *str)
{
    printf("valide\n");
}
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// void    ft_parsing(int ac, char **av)
int main(int ac, char *av[])
{
    int i;

    if (ac > 2)
    {
        i = 1;
        while(i < ac)
        {
            if(av[i][0] != '"' || av[i][0] != 39)
                printf("her\n");
            else if ((av[i][0] == 34 && av[i][ft_strlen(av[i] - 1)] == 34)
             || (av[i][0] == 39 && av[i][ft_strlen(av[i] - 1)] == 39))
                ft_string(av[i]);
            else
                return (0);
            i++;
        }        
    }
    else
        return (0);
}