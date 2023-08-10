#include <unistd.h>

int check_doubles(char *s, char c, int index)
{
    int j;

    j = 0;
    while (j < index && s[j] != '\0')
    {
        if (s[j] == c)
            return (1);
        j++;
    }
    return (0);
}

int is_in_string(char *s, char c)
{
    int i;

    i = 0;
    while(s[i] != '\0')
    {
        if (s[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 3)
    {
        while (argv[1][i] != '\0')
        {
            if (check_doubles(argv[1], argv[1][i], i) == 0 &&
                is_in_string(argv[2], argv[1][i]) == 1)
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
