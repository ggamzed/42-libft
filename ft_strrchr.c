#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	s_last;

	s_last = ft_strlen(s);
	while (s_last >= 0)
	{
		if (s[s_last] == (char)c)
			return ((char *)(s + s_last));
		s_last--;
	}
	return (NULL);
}
