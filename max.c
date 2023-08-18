int max(int *tab, unsigned int len)
{
    int result;

    if (len == 0)
        return (0);
    result = tab[--len];
    while(len--)
    {
        if (result < tab[len])
            result = tab[len];
    }
    return (result);
}
