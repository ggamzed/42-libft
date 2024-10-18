#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char     *str;
    unsigned int    len;
    unsigned int    i;
    unsigned int    j;

    len = ft_strlen(s1) + ft_strlen(s2) + 1;

    str = (char *)malloc(len * sizeof(char));
    if(!str)
        return (NULL);
    i = ft_strlcpy(str, s1, len);
    j = ft_strlcpy(&str[i], s2, len);
    str[j + i] = 0;
    return (str);
}

#include <stdio.h>

int main()
{
    char *st = "hello ";
    char *st2 = "world.";

    printf("%s\n", ft_strjoin(st, st2));
}