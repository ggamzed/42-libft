#include <stdlib.h>

char	*strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if(!haystack || !needle)
		return (NULL);
	if(!needle || !(*needle))
		return ((char *)haystack);
	i = 0;
	while(haystack[i] && i < len)
	{
		j = 0;
		while(haystack[i + j] && needle[j] && i + j < len && haystack[i + j] == needle[j])
			j++;
		if(!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

#include <stdio.h>

int main()
{
	char st[] = "hello world";
	char st2[] = "wor";

	printf("%s", strnstr(st, st2, 12));
}