#include "libft.h"

static int	ft_charcmp(char c1, char c2)
{
	if((unsigned char)c1 != (unsigned char)c2)
		return (1);
	return (0);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	
	i = 0;
	while(s1[i] && s2[i] && i < n)
	{
		if(ft_charcmp(s1[i], s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	if(i < n)
		return (ft_charcmp(s1[i], s2[i]));
	return (0);
}
