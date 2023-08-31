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
/*
MAN PAGE
NAME
     stpcpy, stpncpy, strcpy, strncpy -- copy strings

LIBRARY
     Standard C Library (libc, -lc)

SYNOPSIS
     #include <string.h>

     char *
     stpcpy(char * dst, const char * src);

     char *
     stpncpy(char * dst, const char * src, size_t len);

     char *
     strcpy(char * dst, const char * src);

     char *
     strncpy(char * dst, const char * src, size_t len);

DESCRIPTION
     The stpcpy() and strcpy() functions copy the string src to dst (including
     the terminating `\0' character.)

     The stpncpy() and strncpy() functions copy at most len characters from
     src into dst.  If src is less than len characters long, the remainder of
     dst is filled with `\0' characters.  Otherwise, dst is not terminated.

     The source and destination strings should not overlap, as the behavior is
     undefined.

RETURN VALUES
     The strcpy() and strncpy() functions return dst.  The stpcpy() and
     stpncpy() functions return a pointer to the terminating `\0' character of
     dst.  If stpncpy() does not terminate dst with a NUL character, it
     instead returns a pointer to dst[n] (which does not necessarily refer to
     a valid memory location.)
*/
   
int main(void)
{
    char src[] = "bijour";
    char dst[7];
    ft_strcpy(dst, src);
    printf("%s\n", dst);
    return (0);
}
