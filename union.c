#include <unistd.h>
// union PIMPED juillet 2023
// warning la variable return_code n'est
// utile qu'avec le nouveau compilo gcc
// qui demande d'utiliser le retour de write
int    is_in_string(char c, char *str)
{
    int    i;

    i = 0;
    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int    is_before(char c, char *str, int index)
{
    int    j;

    j = 0;
    while (j < index)
    {
        if (str[j] == c)
            return (1);
        j++;
    }
    return (0);
}

int    main(int argc, char **argv)
{
    int    i;
    int    return_code;

    if (argc == 3)
    {
        i = 0;
        while (argv[1][i] != '\0')
        {
            if (is_before(argv[1][i], argv[1], i) == 0)
                return_code =  write (1, &argv[1][i], 1);
                (void) return_code;
            i++;
        }
        i = 0;
        while (argv[2][i] != '\0')
        {
            if (is_in_string(argv[2][i], argv[1]) == 1)
                i++;
            else if (is_before(argv[2][i], argv[2], i) == 1)
                i++;
            return_code = write (1, &argv[2][i], 1);
            (void) return_code;
            i++;
        }
    }
    return_code = write (1, "\n", 1);
    (void) return_code;   
    return (0);
}
/*
Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Example:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
*/

// UNION octobre 2022
char    *ft_strcat(char *dest, char *src)
{
    int i;
    int j;
    
    i = 0;
    while (dest[i])
        i++;
    j = 0;
    while (src[j])
    {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return (dest);
}

int is_in_string(char c, char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            return (1);
        }
        i++;
    }
    return (0);
}

int ft_len(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
        i++;
        return (i);
}

void ft_union(char *s1, char *s2)
{
    int     i;
    int     j;
    char    s4[ft_len(s1) +ft_len(s2) + 1];
    char    s3[ft_len(s1) + ft_len(s2) + 1];

    *s4 = '\0';
    ft_strcat(s4, s1);
    ft_strcat(s4, s2);

    i = 0;
    j = 0;
    while (s4[i] != '\0')
    {
        if (!(is_in_string(s4[i], s3)))
        {
            s3[j] = s4[i];
            j++;
        }
        i++;
    }
    write(1, &s3, j);
}

int main(int ac, char **av)
{
    if (ac == 3)
        ft_union(av[1], av[2]);
    write(1, "\n", 1);
    return (0);
}
