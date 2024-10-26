#include "libft.h"
#include <unistd.h>

void    ft_putnbr_fd(int n, int fd)
{
    long    int nb;

    nb = n;
    if (nb < 0)
    {
        write(fd, "-", 1);
        nb *= -1;
    }
    if(nb  > 9)
    {
        ft_putnbr_fd((nb / 10), fd);
        ft_putnbr_fd((nb % 10), fd);
    }
    else
        ft_putchar_fd((nb + '0'), fd);
}