/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemirci <gdemirci@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:33:35 by gdemirci          #+#    #+#             */
/*   Updated: 2024/10/28 13:33:35 by gdemirci         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_memory(char **str, size_t i)
{
	while (i > 0)
		free(str[--i]);
	free(str);
	return (NULL);
}

static int	count_strings(char *str, char sep)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == sep))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(str[i] == sep))
			i++;
	}
	return (count);
}

static int	word_len(const char *str, char sep)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] && (str[i] == sep))
			return (i);
		i++;
	}
	return (i);
}

static char	**alloc_strings(char **strs, char const *s, char c, size_t w_count)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (s[i] && j < w_count)
	{
		while (s[i] && (s[i] == c))
			i++;
		if (s[i])
		{
			strs[j] = ft_substr(s, i, word_len(&s[i], c));
			if (!strs[j])
				return (free_memory(strs, j));
			j++;
		}
		while (s[i] && !(s[i] == c))
			i++;
	}
	strs[j] = 0;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	word_count;

	if (!s)
		return (NULL);
	word_count = count_strings((char *)s, c);
	strings = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!strings)
		return (NULL);
	return (alloc_strings(strings, s, c, word_count));
}
