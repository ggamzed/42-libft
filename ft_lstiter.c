#include "libft.h"

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if(f)
    {
        while(lst)
        {
            f(lst->content);
            lst = lst->next;
        }
    }
}

#include <stdio.h>
void print_content(void *content)
{
    *(int *)content += 10;
    printf("%d\n", *(int *)content);
}

int main()
{
    t_list *head;
    int *a;
    int *b;
    int *c;

    a = malloc(sizeof(int));
    *a = 23;
    b = malloc(sizeof(int));
    *b = 30;
    c = malloc(sizeof(int));
    *c = 45;

    head = ft_lstnew(a);
    ft_lstadd_back(&head, ft_lstnew(b));
    ft_lstadd_back(&head, ft_lstnew(c));
    ft_lstiter(head, print_content);
}