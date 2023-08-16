#include <unistd.h>

// ROSTRING FIRST (NOT PIMPED)

int    main(int argc, char **argv)
{
    int    start;
    int    end;
    int    i;
    int    flag;

    start = 0;
    end = 0;
    i = 0;
    flag = 0;
    
       if (argc == 2)
       {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        start = i;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i++;
        end = i;
        while (argv[1][i] == ' ' && argv[1][i] == '\t')
                i++;
        while(argv[1][i] != '\0')
        {
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                write(1, &argv[1][i], 1);
                flag = 1;
                i++;
            }
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] != '\0' && (argv[1][i - 1] == ' '|| argv[1][i - 1] == '\t'))    
                write(1, " ", 1);
       }
        if (flag == 1)
            write(1, " ", 1);
        while (start < end)
        {
            write(1, &argv[1][start], 1);
            start++;
        }
       }
       write(1, "\n", 1);
       return (0);
}
// ROSTRING PIMPED
// WARNING LA VARIABLE int return_code; n'est utilisée que pour 
// le nouveau compilateur gcc qui demande d'utiliser le retour de write sans quoi ça ne compile pas.
int    skip_ispace(char *str, int i)
{
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return (i);
}

int    skip_word(char *str, int i)
{
    while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t')
        i++;
    return (i);
}

void    print_first_word(char *str, int start, int end)
{
    int    return_code;

    return_code = 0;
    while (start < end)
    {
        return_code = write(1, &str[start], 1);
        (void) return_code;
        start++;
    }
}

int    main(int argc, char **argv)
{
    int    return_code;
    int    start;
    int    end;
    int    i;
    int    flag;

    i = 0;
    flag = 0;

    if (argc > 1 && argv[1][i] != '\0')
    {
        i = skip_ispace(argv[1], i);
        start = i;
        i = skip_word(argv[1], i);
        end = i;
        i = skip_ispace(argv[1], i);
        while(argv[1][i] != '\0')
        {
            while (argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                return_code = write(1, &argv[1][i], 1);
                (void) return_code;
                flag = 1;
                i++;
            }
            i = skip_ispace (argv[1], i);
            if (argv[1][i] != '\0' && (argv[1][i - 1] == ' '|| argv[1][i - 1] == '\t'))
            {
                return_code = write(1, " ", 1);
                (void) return_code;
            }
        }
        if (flag == 1)
        {
            return_code = write(1, " ", 1);
            (void) return_code;
        }
        print_first_word(argv[1], start, end);
    }
    return_code = write(1, "\n", 1);
    (void) return_code;
    return (0);
}
/*
Assignment name  : rostring
Expected files   : rostring.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n.

Example:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
*/
