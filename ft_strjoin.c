#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char     *str;
    size_t    len;

    len = ft_strlen(s1) + ft_strlen(s2) + 1;
    str = (char *)malloc(len * sizeof(char));
    if(!str)
        return (NULL);
    ft_strlcpy(str, s1, len);
    ft_strlcat(str, s2, len);
    return (str);
}
