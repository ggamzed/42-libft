#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    size_t    j;
    char    *str;

    if(!s)
        return (NULL);
    str = (char *)malloc((len + 1) * sizeof(*s));
    if(!str)
        return (NULL);
    i = 0;
    j = 0;
    while(s[i])
    {
        if(i >= start && j < len)
        {
            str[j] = s[i];
            j++;
        }
        i++;
    }
    str[j] = 0;
    return (str);
}
