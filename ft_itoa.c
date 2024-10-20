#include "libft.h"

static unsigned int	ft_num_len(int n)
{
	int	len;

	len = 0;
	if(n < 0)
	{
		len++;
		n *= -1;
	}
	len = 0;
	while(n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}
#include <stdio.h>
char *ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_num_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if(!str)
		return (NULL);
	if(n < 0)
	{
		n *= -1;
		str[0] = '-';
	}
	str[len] = '\0';
	//len--;
	while(n > 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	if (len == 0 && str[0] != '-')
    {
        str[len] = '0';
    }
	return (str);
}
