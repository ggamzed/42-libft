#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;

	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (size + ft_strlen(src));
	ft_strlcpy(&dst[dst_len], src, size - dst_len);
	return (dst_len + ft_strlen(src));
}
