#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if(!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

#include <stdio.h>
int main()
{
    t_list *head;
    head = ft_lstnew(ft_strdup("geldi"));
    ft_lstadd_front(&head, ft_lstnew(ft_strdup("okula")));
    ft_lstadd_front(&head, ft_lstnew(ft_strdup("gamze")));
    printf("%s\n", (char *)head->content);
}