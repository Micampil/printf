# ft_printf

A custom implementation of the C standard library `printf` function, created as part of the 42 school curriculum.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Supported Format Specifiers](#supported-format-specifiers)
- [Function Prototypes](#function-prototypes)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Testing](#testing)
- [Implementation Details](#implementation-details)
- [Author](#author)

## About

`ft_printf` is a recreation of the standard C library function `printf`. This project aims to understand variadic functions and improve skills in C programming by implementing a complex function from scratch. The function processes a format string and outputs formatted data to the standard output.

## Features

- ✅ Handles multiple format specifiers
- ✅ Returns the number of characters printed
- ✅ Proper error handling for edge cases
- ✅ Memory efficient implementation
- ✅ Compatible with 42 Norm standards
- ✅ Integrated with custom libft library

## Installation

1. Clone the repository:
```bash
git clone <your-repo-url>
cd printf
```

2. Compile the library:
```bash
make
```

3. To clean object files:
```bash
make clean
```

4. To remove all generated files:
```bash
make fclean
```

5. To recompile everything:
```bash
make re
```

## Usage

Include the header file in your C program:

```c
#include "libftprintf.h"
```

Compile your program with the library:

```bash
gcc -Wall -Wextra -Werror your_program.c libftprintf.a -o your_program
```

## Supported Format Specifiers

| Specifier | Description | Type |
|-----------|-------------|------|
| `%c` | Single character | `char` |
| `%s` | String of characters | `char *` |
| `%p` | Pointer address | `void *` |
| `%d` | Decimal (base 10) number | `int` |
| `%i` | Integer (base 10) number | `int` |
| `%u` | Unsigned decimal number | `unsigned int` |
| `%x` | Hexadecimal (base 16) lowercase | `unsigned int` |
| `%X` | Hexadecimal (base 16) uppercase | `unsigned int` |
| `%%` | Literal percent sign | - |

## Function Prototypes

### Main Function
```c
int ft_printf(const char *format, ...);
```

### Helper Functions
```c
int ft_putchar(char c);
int ft_putstr(char *s);
int ft_putnbr(int n);
int ft_putnbr_unsigned(unsigned int n);
int ft_putnbr_hex(unsigned long n, int uppercase);
int ft_print_ptr(void *ptr);
```

## Examples

```c
#include "libftprintf.h"

int main(void)
{
    int count;
    
    // Basic usage
    count = ft_printf("Hello, World!\n");
    ft_printf("Characters printed: %d\n", count);
    
    // Different format specifiers
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "42 Lisboa");
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 42U);
    ft_printf("Hex lowercase: %x\n", 255);
    ft_printf("Hex uppercase: %X\n", 255);
    ft_printf("Pointer: %p\n", &count);
    ft_printf("Percent: %%\n");
    
    return (0);
}
```

Expected Output:
```
Hello, World!
Characters printed: 14
Character: A
String: 42 Lisboa
Decimal: 42
Integer: -42
Unsigned: 42
Hex lowercase: ff
Hex uppercase: FF
Pointer: 0x7fff5fbff6ac
Percent: %
```

## Project Structure

```
printf/
├── ft_printf.c          # Main ft_printf function
├── ft_printf_utils.c    # Basic utility functions
├── ft_printf_hex.c      # Hexadecimal and pointer handling
├── libftprintf.h        # Header file
├── Makefile            # Compilation rules
├── README.md           # This file
└── libft/              # Custom C library
    ├── libft.h
    ├── Makefile
    └── *.c files
```

## Compilation

The project uses a Makefile with the following rules:

- `make` or `make all`: Compiles the library
- `make clean`: Removes object files
- `make fclean`: Removes object files and the library
- `make re`: Recompiles everything from scratch
- `make bonus`: Compiles with bonus features (if applicable)

Compilation flags used:
- `-Wall -Wextra -Werror`: Enable all warnings and treat them as errors
- Adheres to 42 Norm coding standards

## Testing

To test the function, you can create a simple test file:

```c
// test.c
#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
    int ft_ret, printf_ret;
    
    ft_ret = ft_printf("ft_printf: %d %s %c\n", 42, "test", 'A');
    printf_ret = printf("printf:    %d %s %c\n", 42, "test", 'A');
    
    ft_printf("ft_printf returned: %d\n", ft_ret);
    printf("printf returned: %d\n", printf_ret);
    
    return (0);
}
```

Compile and run:
```bash
gcc -Wall -Wextra -Werror test.c libftprintf.a -o test
./test
```

## Implementation Details

### Key Features:

1. **Variadic Functions**: Uses `va_list`, `va_start`, `va_arg`, and `va_end` to handle variable arguments.

2. **Character Counting**: Returns the total number of characters printed, maintaining compatibility with the original `printf`.

3. **Error Handling**: 
   - Returns -1 if format string is NULL
   - Handles NULL string pointers by printing "(null)"
   - Handles NULL pointers by printing "(nil)"

4. **Memory Management**: No dynamic memory allocation used, making it safe from memory leaks.

5. **Edge Cases**:
   - Handles `INT_MIN` (-2147483648) correctly
   - Proper hexadecimal formatting for both uppercase and lowercase
   - Correct pointer address formatting with "0x" prefix

### Architecture:

The implementation is modular with separate files for different functionalities:
- Core logic in `ft_printf.c`
- Basic output functions in `ft_printf_utils.c`
- Hexadecimal and pointer functions in `ft_printf_hex.c`

## Author

**Micampil** - micampil@student.42lisboa.com

Created as part of the 42 Lisboa curriculum.

---

*This project is part of the 42 school common core curriculum and follows the 42 Norm coding standards.*
