#include <unistd.h>

void    print_first_word(char *s)
{
    int i = 0;

    while (s[i] == ' ' || s[i] == '\t')
        i++;
    while (s[i] != '\0' && s[i] != ' ' && s[i] != '\t')
    {
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_first_word(argv[1]);
    write(1, "\n", 1);
    return (0);
}
