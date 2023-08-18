#include <stdlib.h>

int delimiter_len(char *s, int i)
{
    while (s[i] != '\0' && (s[i] == 32 || s[i] == 9 || s[i] == 13))
        i++;
    return (i);
}

int word_len(char *s, int i)
{
    while (s[i] != '\0' && s[i] != 32 && s[i] != 9 && s[i] != 13)
        i++;
    return (i);
}

int is_delimiter(char c)
{
    if (c != '\0' && (c == 32 || c == 9 || c == 13))
        return (1);
    return (0);
}

int is_word(char c)
{
    if (c != '\0' && c != 32 && c != 9 && c != 13)
        return(1);
    return(0);
}

int number_of_words(char *s)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (s[i] != '\0')
    {
        i = delimiter_len(s, i);
        if (is_word(s[i]) == 1)
            j++;
        i = word_len(s, i);

    }
    return (j);
}

char    *get_word(char *s)
{
    int     i;
    char    *str;

    i = 0;
    while(is_delimiter(s[i]) == 1)
        i++;
    str = malloc(sizeof(*str) * (i + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (is_word(s[i]) == 1)
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
        i = delimiter_len(str, i);
        if (is_word(str[i]) == 1)
        {
            tab[j] = get_word(str + i);
            j++;
        }
        i = word_len(str, i);
    }
    tab[j] = NULL;
    return (tab);
}
