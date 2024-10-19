#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *str;

    if(!s1)
        return (NULL);
    str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
    if(!str)
        return (NULL);
    ft_strlcpy(str, s1, ft_strlen(s1) + 1);
    return (str);
}
