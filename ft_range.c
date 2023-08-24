#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*rrange;
	int	n;
	int	i;

	n = end - start;
	if (n < 0)
		n = -n;
	if (n = 0)
		return (0);
	rrange = malloc(sizeof(*rrange) * (n + 1));
	if (rrange == NULL)
		return (NULL);
	i = 0;
	while (n >= 0)
	{
		rrange[i] = start;
		i++;
		n--;
		start++;
	}
	return (rrange);
}
/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
