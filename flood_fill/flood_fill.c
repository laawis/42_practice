#include "flood_fill.h"

void  flood_fill(char **tab, t_point size, t_point begin)
{
    int    tmp;

    if (begin.x < 0 || begin.y < 0 || begin.x > size.x - 1 || begin.y > size.y - 1)
        return ;
    tmp = tab[begin.y][begin.x];
    tab[begin.y][begin.x] = 'F';
    if (begin.y - 1 >= 0 && tmp == tab[begin.y - 1][begin.x])
        flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
    if (begin.y + 1 < size.y && tmp == tab[begin.y + 1][begin.x])
        flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
    if (begin.x - 1 >= 0 && tmp == tab[begin.y][begin.x - 1])
        flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
    if (begin.x + 1 < size.x && tmp == tab[begin.y][begin.x + 1])
        flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
}
