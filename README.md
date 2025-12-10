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
| Function | Description |
|----------|-------------|
| `ft_strlen` | Calculate string length |
| `ft_strchr` | Locate character in string |
| `ft_strrchr` | Locate character in string (from end) |
| `ft_strnstr` | Locate substring in string |
| `ft_strncmp` | Compare strings up to n characters |
| `ft_strdup` | Duplicate string |
| `ft_substr` | Extract substring |
| `ft_strjoin` | Join two strings |
| `ft_strtrim` | Remove specified characters from start/end |
| `ft_split` | Split string by delimiter into array |

### Memory Management
| Function | Description |
|----------|-------------|
| `ft_memset` | Fill memory with constant byte |
| `ft_bzero` | Zero out memory |
| `ft_memcpy` | Copy memory area |
| `ft_memmove` | Copy memory (handles overlap) |
| `ft_memchr` | Scan memory for character |
| `ft_memcmp` | Compare memory areas |
| `ft_calloc` | Allocate and zero memory |

### Character Checks & Conversion
| Function | Description |
|----------|-------------|
| `ft_isalpha` | Check if alphabetic character |
| `ft_isdigit` | Check if digit character |
| `ft_isalnum` | Check if alphanumeric character |
| `ft_isascii` | Check if ASCII character |
| `ft_isprint` | Check if printable character |
| `ft_toupper` | Convert to uppercase |
| `ft_tolower` | Convert to lowercase |

### String to Integer
| Function | Description |
|----------|-------------|
| `ft_atoi` | Convert string to integer |

### File Descriptor Output
| Function | Description |
|----------|-------------|
| `ft_putchar_fd` | Output character to file descriptor |
| `ft_putstr_fd` | Output string to file descriptor |
| `ft_putendl_fd` | Output string + newline to file descriptor |
| `ft_putnbr_fd` | Output integer to file descriptor |

### Advanced String Functions
| Function | Description |
|----------|-------------|
| `ft_strmapi` | Apply function to each character with index |
| `ft_striteri` | Iterate string with function and index |

## Bonus: Linked List Functions

```c
typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;
```

### Bonus: Linked List Operations
| Function | Description |
|----------|-------------|
| `ft_lstnew` | Create new node |
| `ft_lstadd_front` | Add node at beginning of list |
| `ft_lstadd_back` | Add node at end of list |
| `ft_lstsize` | Count number of nodes in list |
| `ft_lstlast` | Get last node of list |
| `ft_lstdelone` | Delete single node |
| `ft_lstclear` | Delete entire list |
| `ft_lstiter` | Apply function to each node |
| `ft_lstmap` | Create new list with function applied |

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