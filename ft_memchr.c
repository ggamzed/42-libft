#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if(!s)
		return (NULL);
	i = 0;
	while(i < n)
	{
		if(*(unsigned char*)(s + i) == (unsigned char)c)
			return ((s + i));
		i++;
	}
	return (NULL);
}


int main(void)
{
	char st[] = "hello world";
	char c = 'w';
	printf("%s", ft_memchr(st, c, 10));
}