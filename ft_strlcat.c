#include "libft.h"

size_t  ft_strlcat(char *dst, const char *src, size_t size)
{
    size_t  i;
    size_t  j;
    size_t  dst_len;
    size_t  src_len;

    src_len = ft_strlen(src);
    dst_len = ft_strlen(dst);
    j = dst_len;
    i = 0;
    if(dst_len < size - 1 && size > 0)
    {
        while(src[i] && dst_len + i < size - 1)
        {
            dst[j] = src[i];
            j++;
            i++;
        }
        dst[j] = 0;
    }
    if(dst_len >= size)
        dst_len = size;
    return (dst_len + src_len);
}