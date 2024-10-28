/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:56 by gdemirci          #+#    #+#             */
/*   Updated: 2024/10/28 12:20:58 by gdemirci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_num_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	long_n;

	long_n = (long)n;
	len = ft_num_len(long_n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (long_n < 0)
	{
		long_n *= -1;
		str[0] = '-';
	}
	if (long_n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (long_n > 0)
	{
		str[--len] = (long_n % 10) + '0';
		long_n /= 10;
	}
	return (str);
}
