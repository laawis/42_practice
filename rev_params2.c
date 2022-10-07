#include <unistd.h>

int main(int ac, char **av)
{
    int j;
    
    j = 0;
    while (ac > 1)
    {
        j = 0;
        while (av[ac - 1][j])
        {
            write(1, &av[ac - 1][j], 1);
            j++;
        }
        j = 0;
        ac--;
        write(1, "\n", 1);
    }
}
