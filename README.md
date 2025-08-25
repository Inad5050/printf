<h1 align="center">ft_printf | 42 School Project</h1>

Este repositorio contiene mi implementación del proyecto ft_printf del cursus de 42. El objetivo es replicar el comportamiento de la función printf() de la librería estándar de C stdio.h.

<h2 align="center">
    <a href="#sobre-el-proyecto">Sobre el proyecto</a>
    <span> · </span>
    <a href="#índice">Índice</a>
    <span> · </span>
    <a href="#requisitos">Requisitos</a>
    <span> · </span>
    <a href="#instrucciones">Instrucciones</a>
</h2>
## Sobre el proyecto

Este proyecto consiste en crear una librería con una función, ft_printf, que imita el funcionamiento original de printf. No es necesario implementar la gestión del búfer. La función debe manejar los siguientes especificadores de formato:
* %c: Para imprimir un solo carácter.
* %s: Para imprimir una cadena de caracteres.
* %p: Para imprimir la dirección de un puntero en formato hexadecimal.
* %d: Para imprimir un número decimal (base 10).
* %i: Para imprimir un entero en base 10.
* %u: Para imprimir un número decimal sin signo (base 10).
* %x: Para imprimir un número en formato hexadecimal (minúsculas).
* %X: Para imprimir un número en formato hexadecimal (mayúsculas).
* %%: Para imprimir el símbolo de porcentaje.

## Estructura

El principal desafío del proyecto es la gestión de un número variable de argumentos. Para ello, se han utilizado las macros de la librería <stdarg.h>: va_list, va_start, va_arg y va_end.

El flujo del programa es el siguiente:

* La función ft_printf recorre la cadena de formato.

* Cuando encuentra un carácter %, llama a la función selection.

* Selection determina qué tipo de dato se debe imprimir basándose en el carácter que sigue al % y llama a la función de impresión correspondiente (por ejemplo, print_c para %c).

* Cada función de impresión se encarga de escribir el argumento correspondiente en la salida estándar y devuelve el número de caracteres impresos.

## Funciones principales

El archivo printer.c contiene las funciones encargadas de gestionar cada tipo de formato:

* print_c(char arg): Imprime un único carácter y devuelve 1.

* print_s(char *arg): Imprime una cadena de caracteres. Si el puntero es nulo, imprime (null). Devuelve la longitud de la cadena impresa.

* print_d(int arg, char format): Imprime un número entero con signo (d o i) o sin signo (u), utilizando las funciones auxiliares putnbr_alt y putnbr_alt_u. Devuelve el número de dígitos impresos.

* print_x(size_t arg, char format, int count): Imprime un número en formato hexadecimal, ya sea en minúsculas (x), mayúsculas (X) o como parte de un puntero (p). Es una función recursiva que construye el número y devuelve el número de caracteres hexadecimales impresos.

## Funciones auxiliares

El archivo auxiliars.c contiene las funciones de apoyo para la impresión de números:

* putnbr_alt(int n, int count): Función recursiva que imprime un número entero (int) gestionando correctamente los números negativos y el caso límite INT_MIN. Devuelve el número de caracteres impresos.

* putnbr_alt_u(unsigned int n, int count): Función recursiva que imprime un número entero sin signo (unsigned int). Devuelve el número de caracteres impresos.

## Requisitos

Para compilar y utilizar esta librería, necesitarás:

* Un compilador de C, como gcc.

* Las librerías estándar <unistd.h>, <stdlib.h> y <stdarg.h>.

## Instrucciones
#### 1. Compilar la librería

Para compilar los archivos y crear la librería libftprintf.a, clona el repositorio, navega hasta su directorio y ejecuta:

$ make

#### 2. Limpiar archivos

Para eliminar los archivos objeto (.o) generados durante la compilación:

$ make clean

Para eliminar tanto los archivos objeto como la librería (libftprintf.a):

$ make fclean

Para limpiar todo y recompilar la librería:

$ make re

#### 3. Usar en tu código

Para utilizar ft_printf en tus propios proyectos, incluye el archivo de cabecera ft_printf.h y enlaza la librería libftprintf.a durante la compilación.

    #include "ft_printf.h"
    int main(void)
    {
        ft_printf("Hola, %s! Tienes %d mensajes.\n", "mundo", 5);    
        return (0);    
    }
