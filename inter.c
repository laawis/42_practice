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
/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "rien" "cette phrase ne cache rien" | cat -e
rien$
$>./inter | cat -e
$
*/
