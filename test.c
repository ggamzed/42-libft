#include <stdio.h>
#include "libft.h"

// Dinamik olarak işlevi çağıran test fonksiyonu
void    test_is(int (*is_func)(int))
{
    char test_chars[] = {'3', 't', '0', '8', 'a', 'A', 'z', '0', '&', '\n'};
    int i;
    
    i = 0;
    while (i < 10)
    {
        if (is_func(test_chars[i]))
            printf("'%c' valid\n", test_chars[i]);
        else
            printf("'%c' NOT valid\n", test_chars[i]);
        i++;
    }
}

void    test_strlen()
{
    char *str_string[] = {"Hello", "world", "Mi", "nombre", "es", "Gamze", NULL};
    int i;
    int j;

    i = 0;
    while(str_string[i])
    {
        printf("len: %zu\n", ft_strlen(str_string[i]));
        i++;
    }
}

void    test_ft_memset()
{
    char buffer1[20];

    // Test verilerini temizle (null terminatörlü stringler gibi)
    ft_memset(buffer1, 0, sizeof(buffer1));
    printf("ft_memset ile doldurulan bellek: %s\n", buffer1);
    // ft_memset kullanarak buffer1'i doldur
    ft_memset(buffer1, 'A', 10);
    printf("ft_memset ile doldurulan bellek: %s\n", buffer1);
    
}

void    test_ft_bzero()
{
    char buffer[20];
    ft_bzero(buffer, sizeof(buffer));
    printf("ft_bzero ile doldurulan bellek: %s\n", buffer);
}

void    test_ft_memcpy()
{
    int    src[] = {1, 2, 3, 4};
    int    dest[20];
    size_t  n = 4;

    ft_memcpy(dest, src, n * sizeof(int));
    printf("Source: %d\n", src[2]);
    printf("Destination after memcpy: %d\n", dest[2]);

    char src1[] = "Hello";
    char dest1[6]; // 'Hello' + '\0' için 6 byte
    ft_memcpy(dest1, src1, 6); // 6 byte kopyala, böylece sonlandırıcıyı da kopyalar
    dest1[5] = '\0';
    printf("Dest1 after memcpy: %s\n", dest1);
}

void    test_ft_memmove()
{
    char str1[50] = "Hello, World!";
    char str2[50] = "Goodbye, World!";
    
    printf("Orijinal str1: %s\n", str1);
    printf("Orijinal str2: %s\n", str2);
    
    // 1. Test: Çakışmayan bellek alanı
    ft_memmove(str1 + 7, str2, 6); // "Googbye, " ifadesini "World!" kısmına kopyala
    printf("Test 1 - str1 (Çakışmayan): %s\n", str1); // Çıktı: "Hello, Goodbye"
    
    // 2. Test: Çakışan bellek alanı
    char str3[] = "1234567890";
    printf("Orijinal str3: %s\n", str3);
    ft_memmove(str3 + 2, str3, 8); // "12345678" ifadesini "34567890" kısmına kaydır
    printf("Test 2 - str3 (Çakışan): %s\n", str3); // Çıktı: "1212345678"
    
}

void    test_ft_strlcpy()
{
    char dest[20];
    const char *source = "Hello, World!";

    // Test 1: Normal kopyalama
    size_t result1 = ft_strlcpy(dest, source, sizeof(dest));
    printf("Test 1 - Kopyalanan string: %s\n", dest); // Çıktı: "Hello, World!"
    printf("Test 1 - Kopyalanan uzunluk: %zu\n", result1); // Çıktı: 13

    // Test 2: Yetersiz boyutta hedef
    char small_dest[10];
    size_t result2 = ft_strlcpy(small_dest, source, sizeof(small_dest));
    printf("Test 2 - Kopyalanan string: %s\n", small_dest); // Çıktı: "Hello, Wo"
    printf("Test 2 - Kopyalanan uzunluk: %zu\n", result2); // Çıktı: 13

    // Test 3: Boş kaynak string
    char empty_dest[20];
    size_t result3 = ft_strlcpy(empty_dest, "", sizeof(empty_dest));
    printf("Test 3 - Kopyalanan string: %s\n", empty_dest); // Çıktı: ""
    printf("Test 3 - Kopyalanan uzunluk: %zu\n", result3); // Çıktı: 0

    // Test 4: Sıfır boyutlu hedef
    size_t result4 = ft_strlcpy(empty_dest, source, 0);
    printf("Test 4 - Kopyalanan uzunluk: %zu\n", result4); // Çıktı: 13
    printf("Test 4 - Kopyalanan string: %s\n", empty_dest); // Çıktı: ""
}

#include <stdio.h>
#include <string.h>

void test_ft_strlcat() {
    // Test 1: Yeterli hedef dizisi boyutu
    char dst1[20] = "Hello, ";
    char src1[] = "World!";
    size_t dstsize1 = sizeof(dst1);
    size_t result1 = strlcat(dst1, src1, dstsize1);

    printf("Test 1 - Yeterli boyut:\n");
    printf("Birleştirilmiş dizi: %s\n", dst1);
    printf("Dönen değer: %zu\n\n", result1);

    // Test 2: Sınırda hedef dizisi boyutu
    char dst2[12] = "Hello, ";
    char src2[] = "World!";
    size_t dstsize2 = sizeof(dst2);
    size_t result2 = strlcat(dst2, src2, dstsize2);

    printf("Test 2 - Sınırda boyut:\n");
    printf("Birleştirilmiş dizi: %s\n", dst2);
    printf("Dönen değer: %zu\n\n", result2);

    // Test 3: Yetersiz hedef dizisi boyutu
    char dst3[10] = "Hello, ";
    char src3[] = "World!";
    size_t dstsize3 = sizeof(dst3);
    size_t result3 = strlcat(dst3, src3, dstsize3);

    printf("Test 3 - Yetersiz boyut:\n");
    printf("Birleştirilmiş dizi: %s\n", dst3);
    printf("Dönen değer: %zu\n\n", result3);

    // Test 4: Hedef dizisi tamamen dolu
    char dst4[7] = "Hello";
    char src4[] = ", World!";
    size_t dstsize4 = sizeof(dst4);
    size_t result4 = strlcat(dst4, src4, dstsize4);

    printf("Test 4 - Hedef dolu:\n");
    printf("Birleştirilmiş dizi: %s\n", dst4);
    printf("Dönen değer: %zu\n\n", result4);
}

void    test_to(int (*to_func)(int))
{
    char    test_chars[] = {'b', 'A', 'Z', 't', '3', 'k', 'H'};
    int     i;

    i = 0;
    while(i < 7)
    {
        printf("%c ", to_func(test_chars[i]));
        i++;
    }
    printf("\n");
}

void    test_strchr_strrchr(char *(*stchr_func)(const char *, int))
{
    char str[] = "hola!, Mi nombre es Gamze";
    char ch = 'a'; // '\0' aranan karakter olarak da çalışan bir fonk 
    printf("%s \n", stchr_func(str, ch));
}

void    test_strncmp()
{
    char str[] = "heyyo";
	char str2[] = "hello";

	printf("%d\n", ft_strncmp(str, str2, 12));
}

void    test_memchr()
{
    const char st[] = "hello world";
	char c = 'w';
	printf("%s\n", (char *)ft_memchr(st, c, 10));
}

void    test_memcmp()
{
    char st[] = "hello";
	char st2[] = "hello";
	printf("%d", ft_memcmp(st, st2, 5));
}

void    test_strnstr()
{
    char st[] = "hello world";
	char st2[] = "wor";

	printf("%s", strnstr(st, st2, 12));
}

void    test_atoi()
{
    char str[] = "-21";
    printf("%d\n", ft_atoi(str));
}

void    test_calloc()
{
    size_t  elem_count;
    size_t  elem_size;
    int     *arr;
    int     is_all_zero;
    size_t  i;

    elem_count = 5;
    elem_size = sizeof(int);
    arr = (int *)ft_calloc(elem_count, elem_size);
    
    if(!arr)
    {
        printf("bellek tahsis edilemedi\n");
        return;
    }
    is_all_zero = 1;
    i = 0;
    while(i < elem_count)
    {
        if(arr[i] != 0)
        {
            is_all_zero = 0;
            break;
        }
        i++;
    }
    if(is_all_zero)
        printf("başarılı, bellek sıfırlandı\n");
    else
        printf("başarısız, bellek sıfırlanmadı\n");
    
    free(arr);
}

void    test_strdup()
{
    const char *original = "Merhaba, dünya!";
    char *copy = ft_strdup(original);
    
    // Test sonucu
    if (copy == NULL) {
        printf("Bellek tahsisi başarısız oldu!\n");
    } else {
        printf("Orijinal: %s\n", original);
        printf("Kopya: %s\n", copy);
        
        // Kontrol: Kopya orijinal ile aynı mı?
        if (strcmp(original, copy) == 0) {
            printf("Test başarılı: Kopya, orijinal string ile aynı.\n");
        } else {
            printf("Test başarısız: Kopya, orijinal string ile farklı.\n");
        }
        
        // Belleği serbest bırak
        free(copy);
    }
}

int main(void)
{
    printf("Testing ft_isalpha:\n");
    test_is(ft_isalpha);

    printf("\nTesting ft_isdigit:\n");
    test_is(ft_isdigit);

    printf("\nTesting ft_isascii:\n");
    test_is(ft_isascii);

    printf("\nTesting ft_isalnum:\n");
    test_is(ft_isalnum);

    printf("\nTesting ft_isprint:\n");
    test_is(ft_isprint);

    printf("\nTesting ft_strlen:\n");
    test_strlen();

    printf("\nTesting ft_memset:\n");
    test_ft_memset();

    printf("\nTesting ft_bzero:\n");
    test_ft_bzero();

    printf("\nTesting ft_memcpy:\n");
    test_ft_memcpy();

    printf("\nTesting ft_memmove:\n");
    test_ft_memmove();

    printf("\nTesting ft_strlcpy:\n");
    test_ft_strlcpy();

    printf("\nTesting ft_strlcat:\n");
    test_ft_strlcat();

    printf("\nTesting ft_toupper:\n");
    test_to(ft_toupper);

    printf("\nTesting ft_tolower:\n");
    test_to(ft_tolower);

    printf("\nTesting ft_strchr:\n");
    test_strchr_strrchr(ft_strchr);

    printf("\nTesting ft_strrchr:\n");
    test_strchr_strrchr(ft_strrchr);

    printf("\nTesting ft_strncmp:\n");
    test_strncmp();

    printf("\nTesting ft_memchr:\n");
    test_memchr();

    printf("\nTesting ft_memcmp:\n");
    test_memcmp();

    printf("\nTesting ft_strnstr:\n");
    test_strnstr();

    printf("\nTesting ft_atoi:\n");
    test_atoi();

    printf("\nTesting ft_calloc:\n");
    test_calloc();

    printf("\nTesting ft_strdup:\n");
    test_strdup();
}