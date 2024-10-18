#include "libft.h"
#include <stdlib.h>
/*
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

static int  word_len(char *str, char sep)
{
    unsigned int    i;

    i = 0;
    while(str[i])
    {
        if(str[i] && (str[i] != sep))
            return (i - 1);
        i++;
    }
    return (i);
}

static char  *ft_word(char *str, char sep)
{
    unsigned int    i;
    size_t  w_len;
    char    *word;

    //word = ft_strdup(str);
    w_len = word_len(str, sep);
    word = (char *)malloc(sizeof(char) * (w_len + 1));
    if(!word)
        return (NULL);
    i = 0;
    while(str[i] && i <= w_len)
    {
        word[i] = str[i];
        i++;
    }
    word[i] = 0;
    return (word);
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
            strings[j] = ft_word((char *)&s[i], c);
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
*/
#include <stdlib.h>

static char **free_memory(char **str, size_t i)
{
    while (i > 0)
    {
        free(str[i - 1]);
        i--;
    }
    free(str);
    return (NULL);
}

static int count_strings(char *str, char sep)
{
    int i = 0;
    int count = 0;
    int in_word = 0;

    while (str[i])
    {
        if (str[i] == sep)
        {
            if (in_word)
            {
                in_word = 0; // kelimenin sonu
            }
        }
        else
        {
            if (!in_word)
            {
                in_word = 1; // yeni bir kelime başlıyor
                count++;
            }
        }
        i++;
    }
    return (count);
}

static int word_len(char *str, char sep)
{
    int i = 0;

    while (str[i] && str[i] != sep)
        i++;
    return (i);
}

static char *ft_word(char *str, char sep)
{
    unsigned int i;
    size_t w_len;
    char *word;

    w_len = word_len(str, sep);
    word = (char *)malloc(sizeof(char) * (w_len + 1));
    if (!word)
        return (NULL);
    for (i = 0; i < w_len; i++)
        word[i] = str[i];
    word[w_len] = '\0';
    return (word);
}

char **ft_split(char const *s, char c)
{
    char **strings;
    unsigned int i = 0, j = 0;
    size_t word_count;

    if (!s)
        return (NULL);
    word_count = count_strings((char *)s, c);
    strings = (char **)malloc(sizeof(char *) * (word_count + 1));
    if (!strings)
        return (NULL);
    while (s[i] && j < word_count)
    {
        while (s[i] && s[i] == c)
            i++;
        if (s[i])
        {
            strings[j] = ft_word((char *)&s[i], c);
            if (!strings[j])
                return free_memory(strings, j);
            j++;
        }
        while (s[i] && s[i] != c)
            i++;
    }
    strings[j] = NULL;
    return (strings);
}
