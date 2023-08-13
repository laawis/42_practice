#include <unistd.h>

void alpha_mirror(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] = 'Z' - s[i] + 'A';
        else if (s[i] >= 'a' && s[i] <= 'z')
            s[i] = 'z'- s[i] + 'a';
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        alpha_mirror(argv[1]);
    write(1, "\n", 1);
    return (0);
}
