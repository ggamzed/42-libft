#include "libft.h"

int ft_lstsize(t_list *lst)
{
    size_t  count;

    count = 0;
    while(lst->next)
    {
        count++;
        lst->next;
    }
    return (count);
}

#include <stdio.h>
int main()
{
    t_list *head;
    head = ft_lstnew(ft_strdup("geldi"));
    ft_lstadd_front(&head, ft_lstnew(ft_strdup("okula")));
    ft_lstadd_front(&head, ft_lstnew(ft_strdup("gamze")));
    printf("%s\n", ft_lstsize(head));
}