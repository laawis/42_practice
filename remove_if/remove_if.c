# include <stdio.h>

# include "ft_list.h"
// Assignment name  : ft_list_remove_if
// Expected files   : ft_list_remove_if.c
// Allowed functions: free
// --------------------------------------------------------------------------------

// Write a function called ft_list_remove_if that removes from the
// passed list any element the data of which is "equal" to the reference data.

// It will be declared as follows :

// void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

// cmp takes two void* and returns 0 when both parameters are equal.

// You have to use the ft_list.h file, which will contain:

// $>cat ft_list.h
// typedef struct      s_list
// {
//     struct s_list   *next;
//     void            *data;
// }                   t_list;
// $>
void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list  *current;
    t_list  *tmp;


    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
    {
        current = *begin_list;
        *begin_list = (*begin_list)->next;
        free(current);
    }
    current = *begin_list;
    while (current && current->next)
    {
        if (cmp(current->next->data, data_ref) == 0)
        {
            tmp = current->next;
            current->next = tmp->next;
            free(tmp);
        }
        current = current->next;
    }
}

int    cmp(void *a, void *b)
{
    return ((int)a == (int)b);
}

t_list    *lst_new(void *data)
{
    t_list    *new_element;

    new_element = malloc(sizeof(t_list));
    if (new_element == NULL)
        return (NULL);
    new_element->data = data;
    new_element->next = NULL;
    return (new_element);
}

void    print_list(t_list *lst)
{
    while (lst != NULL)
    {
        printf("data : %d\n", (int)lst->data);
        lst = lst->next;
    }
}

int    main(void)
{
    int     i;
    t_list  *element;

    i = 0;w
        while (i < 5)
        {
            element = lst_new((void*)i);
            i++;
        }
    print_list(element);
    ft_list_remove_if(&element, (void*)5, cmp); 
    print_list(element);
    return (0);
}
