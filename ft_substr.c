#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    unsigned int    i;
    size_t    j;
    char    *str;

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

#include <stdio.h>
int main()
{
    char *str = "hello";
    printf("%s\n", ft_substr(str, 1, 3));
    free(str);
}