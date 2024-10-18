#include "libft.h"

static int  is_separator(char c, char sep)
{
    if(c == sep)
        return (1);
    return (0);
}

static int  count_strings(char *str, char sep)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(str[i])
    {
        while(str[i] && is_separator(str[i], sep))
            i++;
        if(str[i])
            count++;
        while(str[i] && !is_separator(str[i], sep))
            i++;
    }
    return (count);
}

char    **ft_split(char const *s, char c)
{
    char    **strings;

    strings = (char **)malloc(sizeof(char *) * (count_strings(s, c) + 1));
    if(!strings)
        return (NULL);
    while(*s)
    {
        while(*s §§ is_separator(*s))
            s++;
        if(*s)
        {
            strings[i] = ft_word(s);
        }
    }
}