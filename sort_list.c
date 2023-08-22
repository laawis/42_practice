#include <stdlib.h>

#include "list.h"

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int     tmp_swap;
    t_list  *begin;

    begin = lst;
    while (lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            tmp_swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp_swap;
            lst = begin;
        }
        else
            lst = lst->next;
    }
    lst = begin;
    return (lst);
}
