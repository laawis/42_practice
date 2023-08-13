#include <unistd.h>

int ft_atoi(char *s)
{
    int i;
    int res;

    i = 0;
    res = 0;
    while (s[i] >= '0'&& s[i] <= '9')
        {
            res = res * 10 + s[i] - '0';
            i++;
        }
    return (res);       
}

void print_hex(int n)
{
    char    hex_base[] = "0123456789abcdef";

    if (n >= 16)
        print_hex(n / 16);
    write(1, &hex_base[n % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return (0);
}
