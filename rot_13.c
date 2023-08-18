#include <unistd.h>

void    rot_13(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
        if ((s[i] >= 'A' && s[i] <= 'M') || (s[i] >= 'a' && s[i] <= 'm'))
            s[i] += 13;
        else if ((s[i] >= 'N' && s[i] <= 'Z') || (s[i]>= 'n' && s[i] <= 'z'))
            s[i] -=13;
        i++;
    }
    write(1 , s, i);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rot_13(argv[1]);
    write(1, "\n", 1);
    return (0);
}
