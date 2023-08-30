#include <stdlib.h>
#include <stdio.h>

VERSION 1
void fprime(unsigned int nb)
{
    unsigned int    prime;

    if (nb == 1)
        printf("1");
    else
    {
        prime = 2;;
        while (nb > 1)
        {
            if (nb % prime == 0)
            {
                printf("%d", prime);
                nb /= prime;
                if (nb > 1)
                    printf("*");
                prime--;
            }
            prime++;
        }
    }
}

int main(int argc, char **argv)
{
    int number;

    if (argc == 2) 
    {
        number = atoi(argv[1]);
        if (number < 0)
        {
            printf("\n");
            return (0);
        }
        fprime(number);
    }
    printf("\n");
    return (0);
}

VERSION MOI
void    prime_factor(unsigned int nb)
{
    unsigned int i;

    i = 2;
    while (nb / i != 0 && i <= nb)
    {
        if (nb % i != 0)
            i++;
        else if (nb % i == 0)
        {
            if (i < nb)
                printf("%d*", i);
            else if (i == nb)
                printf("%d", i);
            nb /= i;
        }
    }
}

int    main(int argc, char **argv)
{
    int number;

    if (argc == 2)
    {
        number = atoi(argv[1]);
        if (errno == ERANGE)
        {
            printf("\n");
            return (1);
        }
        else if (number == 1)
            printf("1");
        else if (number >= 2)
            prime_factor(atoi(argv[1]));
    }
    printf("\n");
    return (0);
}

VERSION PROF

 include <limits.h>
# include <errno.h>

int    is_prime(unsigned int nb)
{
    int    i;

    i = 2;
    if (nb == 0 || nb == 1)
        return (0);
    while (i <= nb / i)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int    print_prime_factor(unsigned int nb, unsigned int div)
{
    if (is_prime(div) && nb % div == 0 && div < nb)
    {
        printf("%d*", div);
        return(nb / div);
    }
    else if (div == nb)
    {
        printf("%d", div);
        return (nb / div);
    }
    return (print_prime_factor(nb, div + 1));
}

void print_all(unsigned int nb)
{
	int    new_nb;
	
    new_nb = print_prime_factor(nb, 2);
    if (new_nb == 1)
        return ;
    print_all(new_nb);
}

// void	print_all_
// -> 20 -> 10 -> 5 -> 1
// -> 2 -> 2 -> 5


int    main(int argc, char **argv)
{
	unsigned int	number;
	
    if (argc == 2)
    {
		number = atoi(argv[1]);
		if (errno == ERANGE)
		{
			printf("\n");
			return (1);
        }
        else if (number == 1)
            printf("1");
        else if (number >= 2)
            print_all(number);
    }
    printf("\n");
    return (0);
}
