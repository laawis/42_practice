#include <unistd.h>

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
