#include "libft.h"

void    *ft_memset(void *s, int c, size_t n)
{
    size_t      i;

    if(!s)
        return (NULL);
    i = 0;
    while(i < n)
    {
        ((unsigned char*)s)[i] = (unsigned char)c;
        i++;
    }
    return (s);
}


#include <stdio.h>

int main()
{
    //char buffer[20];
    //printf("%s", (char *)ft_memset(buffer, 'A', sizeof(buffer)));

    //ft_memset(buffer, 'A', sizeof(buffer));
    //printf("%s", buffer); 

    /*
    char *buffer2;
    int size = 20 * sizeof(char);
    buffer2 = (char *)malloc(size);
    
    ft_memset(buffer2, 'A', size); // sizeof(buffer2) pointer boyutunu ifade ediyor, malloc ile tahsis edilen alanı değil
    printf("%s", buffer2); 

    free(buffer2);
    */

   char buffer3[20];
   ft_memset(&buffer3[2], 'A', 6);
   buffer3[12] = '\0';
   buffer3[0] = 'b';
   buffer3[1] = 'b';
   printf("%s", buffer3);
}