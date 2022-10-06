#include <unistd.h>

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

int main(int ac, char **av)
{
    int i;

    i = ac;
    while (i > 1)
    {
        ft_putstr(av[i - 1]);
        ft_putchar('\n');
        i--;
    }
    return (0);
}
