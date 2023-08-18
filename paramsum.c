#include <unistd.h>
// PARAMSUM 2
void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar((nb % 10) + '0');
}

void    paramsum(int argc)
{
    int i;

    if (argc > 1)
    {
        i = argc - 1;
        ft_putnbr(i);
    }
    if (argc == 1)
        write(1, "0", 1);
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    (void) argv;
    paramsum(argc);
    return (0);
}


// PARAMSUM 1
void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int i)
{
    if (i > 9)
        ft_putnbr(i / 10);
    ft_putchar((i % 10) + '0');
}

int main(int argc, char **argv)
{
    int i;
    (void) (argv);

    if (argc > 1)
    {
        i = argc - 1;
        ft_putnbr(i);
    }
    if (argc == 1)
        ft_putchar('0');
    ft_putchar('\n');
    return (0);
}
