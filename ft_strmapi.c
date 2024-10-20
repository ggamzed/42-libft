#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int	i;
	char	*str;

	str = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if(!str)
		return (NULL);
	i = 0;
	while(s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}


char to_upper(unsigned int index, char c) {
    return (c >= 'a' && c <= 'z') ? c - 32 : c; // Küçük harfleri büyük harfe çevirir
}

#include <stdio.h>
int main()
{
	char st[]= "hello world";
	printf("%s", ft_strmapi(st, to_upper));
}