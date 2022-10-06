#include <unistd.h>

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    ft_display(int ac, char **av)
{
    int i;
    
    i = 1;
    while (i < ac)
    {
        ft_putstr(av[i]);
        write (1, "\n", 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;
    char    *tmp;
    
    i = 1;
    if (ac > 2)
    {
        while (i < ac - 1)
        {
            if (ft_strcmp(av[i], av[i + 1]) > 0)
            {   tmp = av[i];
                av[i] = av[i + 1];
                av[i + 1] = tmp;
                i = 1;
            }
            else
                i++;
        }
    }
    ft_display(ac, av);
    return (0);
}
