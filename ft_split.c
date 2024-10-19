#include "libft.h"

static char  **free_memory(char **str, size_t i)
{
    while(i >= 0)
    {
        free(str[i]);
        i--;
    }
    free(str);
    return (NULL);
}

static int  count_strings(char *str, char sep)
{
    int i;
    int count;

    count = 0;
    i = 0;
    while(str[i])
    {
        while(str[i] && (str[i] == sep))
            i++;
        if(str[i])
            count++;
        while(str[i] && !(str[i] == sep))
            i++;
    }
    return (count);
}

static int  word_len(const char *str, char sep)
{
    unsigned int    i;

    i = 0;
    while(str[i])
    {
        if(str[i] && (str[i] == sep))
            return (i);
        i++;
    }
    return (i);
}

char    **ft_split(char const *s, char c)
{
    char    **strings;
    unsigned int    i;
    unsigned int    j;
    size_t  word_count;

    if(!s)
        return (NULL);
    word_count = count_strings((char *)s, c);
    strings = (char **)malloc(sizeof(char *) * (word_count + 1));
    if(!strings)
        return (NULL);
    i = 0;
    j = 0;
    while(s[i] && j < word_count)
    {
        while(s[i] && (s[i] == c))
            i++;
        if(s[i])
        {
            strings[j] = ft_substr(s, i, word_len(&s[i], c));
            if(!strings[j])
                return free_memory(strings, j);
            j++;
        }
        while(s[i] && !(s[i] == c))
            i++;
    }
    strings[j] = 0;
    return (strings);
}
