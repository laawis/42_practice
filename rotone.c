#include <unistd.h>

void rotone(char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == 'Z' || s[i] == 'z')
            s[i] -= 25;
        else if ((s[i] >= 'a' && s[i] < 'z') || (s[i] >= 'A' && s[i] < 'Z'))
            s[i] += 1;
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rotone(argv[1]);
    write(1, "\n", 1);
    return (0);
}
