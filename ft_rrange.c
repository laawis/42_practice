#include <stdlib.h>
// RECURSIVE RANGE
int *ft_rrange(int start, int end)
{
    int *range;
    int i;
    int n;

    i = 0;
    n = end - start + 1;

    if (start > end)
        return (ft_rrange(end, start));
    range = malloc(sizeof(int) * n);
    if (range)
    {
        while (i < n)
        {
            range[i] = end;
            end--;
            i++;
        }
    }
    return (range);
}
        
