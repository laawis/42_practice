int is_power_of_2(unsigned int n)
{
    unsigned long int   start = 1;

    while (start <= n)
    {
        if (start == n)
            return (1);
        start *= 2;
    }
    return (0);
}
/*
Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Write a function that determines if a given number is a power of 2.

This function returns 1 if the given number is a power of 2, otherwise it returns 0.

Your function must be declared as follows:

int     is_power_of_2(unsigned int n);
*/
