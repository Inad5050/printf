<h1 align="center">School 42 printf()</h1>

This repository contains my implementation of the ft\_printf project from the 42 cursus. The goal is to replicate the behavior of the `printf()` function from the standard C library `stdio.h`.

\<h2 align="center"\>
\<a href="\#about-the-project"\>About the project\</a\>
\<span\> · \</span\>
\<a href="\#index"\>Index\</a\>
\<span\> · \</span\>
\<a href="\#requirements"\>Requirements\</a\>
\<span\> · \</span\>
\<a href="\#instructions"\>Instructions\</a\>
\</h2\>

## About the project

This project consists of creating a library with a function, `ft_printf`, that mimics the original behavior of `printf`. It is not necessary to implement buffer management. The function must handle the following format specifiers:

  * `%c`: To print a single character.
  * `%s`: To print a string of characters.
  * `%p`: To print the address of a pointer in hexadecimal format.
  * `%d`: To print a decimal number (base 10).
  * `%i`: To print an integer in base 10.
  * `%u`: To print an unsigned decimal number (base 10).
  * `%x`: To print a number in hexadecimal format (lowercase).
  * `%X`: To print a number in hexadecimal format (uppercase).
  * `%%`: To print the percentage symbol.

## Structure

The main challenge of the project is managing a variable number of arguments. For this, the macros from the `<stdarg.h>` library have been used: `va_list`, `va_start`, `va_arg`, and `va_end`.

The program flow is as follows:

  * The `ft_printf` function iterates through the format string.

  * When it finds a `%` character, it calls the `selection` function.

  * `selection` determines what type of data should be printed based on the character following the `%` and calls the corresponding printing function (e.g., `print_c` for `%c`).

  * Each printing function is responsible for writing the corresponding argument to the standard output and returns the number of characters printed.

## Main Functions

The `printer.c` file contains the functions responsible for handling each format type:

  * `print_c(char arg)`: Prints a single character and returns 1.

  * `print_s(char *arg)`: Prints a string of characters. If the pointer is null, it prints `(null)`. Returns the length of the printed string.

  * `print_d(int arg, char format)`: Prints a signed (`d` or `i`) or unsigned (`u`) integer, using the helper functions `putnbr_alt` and `putnbr_alt_u`. Returns the number of digits printed.

  * `print_x(size_t arg, char format, int count)`: Prints a number in hexadecimal format, either in lowercase (`x`), uppercase (`X`), or as part of a pointer (`p`). It is a recursive function that builds the number and returns the number of hexadecimal characters printed.

## Helper Functions

The `auxiliars.c` file contains the helper functions for printing numbers:

  * `putnbr_alt(int n, int count)`: A recursive function that prints an integer (`int`), correctly handling negative numbers and the edge case `INT_MIN`. Returns the number of characters printed.

  * `putnbr_alt_u(unsigned int n, int count)`: A recursive function that prints an unsigned integer (`unsigned int`). Returns the number of characters printed.

## Requirements

To compile and use this library, you will need:

  * A C compiler, such as `gcc`.

  * The standard libraries `<unistd.h>`, `<stdlib.h>`, and `<stdarg.h>`.

## Instructions

#### 1\. Compile the library

To compile the files and create the `libftprintf.a` library, clone the repository, navigate to its directory, and run:

`$ make`

#### 2\. Clean files

To remove the object files (`.o`) generated during compilation:

`$ make clean`

To remove both the object files and the library (`libftprintf.a`):

`$ make fclean`

To clean everything and recompile the library:

`$ make re`

#### 3\. Use in your code

To use `ft_printf` in your own projects, include the `ft_printf.h` header file and link the `libftprintf.a` library during compilation.

```
#include "ft_printf.h"
int main(void)
{
    ft_printf("Hello, %s! You have %d messages.\n", "world", 5);
    return (0);
}
```
