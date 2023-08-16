// LAST_WORD VERSION PRO

#include <unistd.h>

int go_to_end(char *s, int i)
{
    while (s[i] != '\0')
        i++;
    return (i);
}

int skip_space(char *s, int i)
{
    while (i > 0 && (s[i] == '\0' || s[i] == ' ' || s[i] == '\t'))
        i--;
    return (i);
}

int skip_word(char *s, int i)
{
    while (i > 0 && s[i] != ' ' && s[i] != '\t')
        i--;
    return (i);
}

void    print_last_word(char *s, int i)
{
    while (i >= 0 && s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
    {
        write(1, &s[i], 1);
        i++;
    }
}

int  main(int argc, char **argv)
{
    int i = 0;

    if (argc == 2)
    {
        if (argv[1][i] != '\0')
        {
            i = go_to_end(argv[1], i);
            i = skip_space(argv[1], i);
            i = skip_word(argv[1], i);
            if (i != 0 && argv[1][++i] != '\0')
                print_last_word(argv[1], i);
            else if (i == 0 && argv[1][i] != '\0')
                print_last_word(argv[1], i);
        } 
    }
    write(1, "\n", 1);
    return (0);
}
