#include <string.h>
#include <stdio.h>

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

int main(void)
{
    char src[] = "bijour";
    char dst[7];
    ft_strcpy(dst, src);
    printf("%s\n", dst);
    return (0);
}
