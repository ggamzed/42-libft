#include "libft.h"

int     ft_atoi(const char *str)
{
    int     i;
    int     sign;
    int     nb;

    if(!str)
        return (0);
    i = 0;
    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    sign = 1;
    if(str[i] == '-')
        sign *= -1;
    if(sign == -1 || str[i] == '+')
        i++;
    nb = 0;
    while(str[i] >= '0' && str[i] <= '9')
        nb = (nb * 10) + (str[i++] - '0');
    return (nb * sign);
}