#include <stdio.h>
int main()
{
    size_t len = 5;
    while(len--)
    {
        printf("%zu", len); // 43210
    }
}