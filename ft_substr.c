#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    size_t    j;
    char    *str;

    if(!s)
        return (NULL);
    if(start > ft_strlen(s))
        return (ft_strdup(""));
    if((ft_strlen(s) - start) < len)
        len = (ft_strlen(s) - start);
    str = (char *)malloc((len + 1) * sizeof(*s));
    if(!str)
        return (NULL);
    ft_strlcpy(str, ((char *)&s[start]), len + 1);
    return (str);
}
