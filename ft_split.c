#include <stdlib.h>

int number_of_words(char *str)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && (str[i] == 32 || str[i] == 9 || str[i] == 13))
            i++;
        if (str[i] != '\0' && str[i] != 32 && str[i] != 9 && str[i] != 13)
            j++;
        while (str[i] != '\0' && str[i] != 32 && str[i] != 9 && str[i] != 13)
            i++;
    }
    return (j);
}

char *get_word(char *s)
{
    int     i;
    char    *str;
    
    i = 0;
    while (s[i] != '\0' && s[i] != 32 && s[i] != 9 && s[i] != 13)
        i++;
    str = malloc(sizeof(*str) * (i + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (s[i] != '\0' && s[i] != 32 && s[i] != 9 && s[i] != 13)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return (str);
}

char    **ft_split(char *str)
{
    char    **tab;
    int     i;
    int     j;

    tab = malloc(sizeof(*tab) * (number_of_words(str) + 1));
    if (tab == NULL)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        while (str[i] != '\0' && (str[i] == 32 || str[i] == 9 || str[i] == 13))
            i++;
        if (str[i] != '\0' && str[i] != 32 && str[i] != 9 && str[i] != 13)
        {
            tab[j] = get_word(str + i);
            j++;
        }
        while (str[i] != '\0' && str[i] != 32 && str[i] != 9 && str[i] != 13)
            i++;
    }
    tab[j] = NULL;
    return (tab);
}
/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str);
*/
