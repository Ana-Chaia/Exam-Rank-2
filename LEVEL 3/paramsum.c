/* Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays the number of arguments passed to it, followed by
a newline.
If there are no arguments, just display a 0 followed by a newline.
Example:
$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$> */

#include <unistd.h>

void    ft_putnbr(int n)
{
    char digit;

    if(n >= 10)
        ft_putnbr(n / 10);
    digit = (n % 10) + '0';
    write(1, &digit, 1);
}

int main (int argc, char **argv)
{
    (void)argv; // é usada para indicar explicitamente que o parâmetro argv não será utilizado no corpo da função. 
    //Em C, quando uma função recebe parâmetros que não são usados, isso pode levar a avisos de "parâmetro não utilizado" durante a compilação. Ao converter o parâmetro para (void), você informa ao compilador que essa variável é intencionalmente não utilizada, suprimindo esses avisos;

    ft_putnbr(argc - 1);
    write(1, "\n", 1);
    return (0);
}