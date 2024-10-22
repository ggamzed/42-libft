#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	if (!str)
		return (0);
	i = 0;
	while (('\t' <= str[i] && str[i] <= '\r') || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	nb = 0;
	while ('0' <= str[i] && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (nb * sign);
}

#include <stdio.h>

int main()
{
    printf("%d", ft_atoi((void*)0));
}