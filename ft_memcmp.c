#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while(i < n)
	{
		if(*(unsigned char*)(s1 + i) != *(unsigned char*)(s2 + i))
			return (*(unsigned char*)(s1 + i) - *(unsigned char*)(s2 + i));
		i++;
	}
	return (0);
}

#include <stdio.h>
int main()
{
	char st[] = "hello";
	char st2[] = "hello";
	printf("%d", ft_memcmp(st, st2, 5));
}