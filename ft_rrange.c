#include <stdlib.h>
// RECURSIVE RANGE
int *ft_rrange(int start, int end)
{
    int *range;
    int i;
    int size;

    i = 0;
    size = end - start;

    if (start > end)
        return (ft_rrange(end, start));
    rrange = malloc(sizeof(i) * (size + 1));
    if (rrange)
    {
        while (i <= size)
        {
            rrange[i] = end;
            end--;
            i++;
        }
    }
    return (rrange);
}
/*       
Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0.
*/
