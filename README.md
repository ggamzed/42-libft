# libft

A custom C library that recreates standard library functions plus additional utilities and linked list operations.

## Installation

```bash
git clone https://github.com/yourusername/libft.git
cd libft
make
```

## Usage

```c
#include "libft.h"

int main()
{
    char *str = ft_strdup("Hello World");
    int len = ft_strlen(str);
    char **split = ft_split(str, ' ');
    
    // Use your custom functions
    free(str);
    // Remember to free split array
    return 0;
}
```

Compile with your project:
```bash
gcc main.c libft.a
```

## Function Categories

### String Manipulation
```c
ft_strlen, ft_strchr, ft_strrchr, ft_strnstr, ft_strcmp
ft_strdup, ft_substr, ft_strjoin, ft_strtrim, ft_split
```

### Memory Management
```c
ft_memset, ft_bzero, ft_memcpy, ft_memmove, ft_memchr, ft_memcmp
ft_calloc
```

### Character Checks & Conversion
```c
ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii, ft_isprint
ft_toupper, ft_tolower
```

### String to Integer
```c
ft_atoi    // String to integer conversion
```

### File Descriptor Output
```c
ft_putchar_fd, ft_putstr_fd, ft_putendl_fd, ft_putnbr_fd
```

### Advanced String Functions
```c
ft_strmapi    // Apply function to each character with index
ft_striteri   // Iterate string with function and index
```

## Bonus: Linked List Functions

```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```

### List Operations
```c
ft_lstnew       // Create new node
ft_lstadd_front // Add node at beginning
ft_lstadd_back  // Add node at end
ft_lstsize      // Count list nodes
ft_lstlast      // Get last node
ft_lstdelone    // Delete single node
ft_lstclear     // Delete entire list
ft_lstiter      // Apply function to each node
ft_lstmap       // Create new list with function applied
```

### Example Linked List Usage
```c
t_list *list = NULL;
t_list *node1 = ft_lstnew(ft_strdup("Hello"));
t_list *node2 = ft_lstnew(ft_strdup("World"));

ft_lstadd_back(&list, node1);
ft_lstadd_back(&list, node2);

printf("List size: %d\n", ft_lstsize(list));
ft_lstclear(&list, free);  // Clean up
```

## Requirements

- GCC compiler
- Unix-like system (Linux, macOS)
- Standard C library headers

## Common Pitfalls

- **NULL protection**: Always check for NULL pointers
- **Memory allocation**: Don't forget to handle malloc failures
- **Edge cases**: Empty strings, zero lengths, etc.
- **Makefile rules**: Ensure clean compilation and relinking

## About

This project is part of 42 School curriculum - your gateway to C programming and the foundation for all future projects.