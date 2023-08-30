#include <unistd.h>

VERSION MOI
void    str_capitalizer(char *str)
{
    int i = 0;

    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i - 1] == ' ' || str[i - 1] == '\t') && (str[i] >= 'a' && str[i] <= 'z'))
            str[i] -= 32;
        if (str[0] >= 'a' && str[0] <= 'z')
            str[0] -= 32;
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i = 1;

    if (argc > 1)
    {
        while (i <= argc)
        {
            str_capitalizer(argv[i]);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}


VERSION 2
void    str_capitalizer(char *str)
{
    int i;

    i = 0;
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    write (1, &str[i], 1);
    i++;
    while (str[i] != '\0')
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t'))
            str[i] -= 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;
    
    i = 1;
    if (argc < 2)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}
