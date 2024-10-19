#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t     i;

    if(!dst || !src)
        return (NULL);
    i = 0;
    if((size_t)dst > (size_t)src)
    {
        i = len - 1;
        while(i >= 0)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i--;
        }
    }
    else
    {
        while(i < len)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dst);
}