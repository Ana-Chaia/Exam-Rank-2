/* Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that displays a number's multiplication table.
The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.
If there are no parameters, the program displays \n.
Examples:
$>./tab_mult 9 1 x9 =9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$> */

#include <unistd.h>

int ft_atoi(char *str)
{
    int sign = 1;
    int result = 0;

    if(*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if(*str == '-')
        sign = -1;
    if(*str == '-' || *str == '+')
        str++;
    while(*str >= '0' && *str <= '9')
    {
        result = (result * 10) + *str - '0';
        str++;
    }
    return (result * sign);
}
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void ft_putnbr(int nb)
{
    if(nb == -2147483648) // tratamento do caso específico onde o número é o menor inteiro possível para um tipo 'int' em C;
    {
        ft_putchar('-'); // printa na tela o sinal negativo;
        ft_putchar('2'); // imprime o '2', que é a primeira cifra do valor absoluto de -2147483648;
        nb = nb % 10000000000; // reduz nb para os dígitos restantes após o '2'. O valor de -2147483648 % 1000000000 é -147483648 (pois -2147483648 = -2 * 1000000000 - 147483648);
        nb = -nb; //  converte -147483648 para 147483648. Esta operação é segura e necessária para tornar o número positivo, facilitando a impressão dos dígitos subsequentes;
    } // o resultado dessa abordagem é que podemos agora imprimir 147483648 usando o mesmo método recursivo que tratamos outros números, chamando ft_putnbr(147483648);
    if (nb < 0)
    {     // para o caso de o número ser negativo (mas não o menor inteiro);
        ft_putchar('-');
        nb = -nb;
    }
    if (nb / 10 > 0)
        ft_putnbr(nb / 10); // recursividade para lidar com múltiplos os dígitos do número;
    ft_putchar(nb % 10 + '0'); // finalmente, 'nb % 10' obtém o último dígito do número e '+ '0'' converte de int para char, para depois imprimir;
}

int main(int argc, char **argv)
{
    int i;
    int nbr;

    if(argc == 1)
        write(1, "\n", 1);
    else
    {
        i = 1;
        nbr = ft_atoi(argv[i]);
        while(i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nbr);
            write(1, " = ", 3);
            ft_putnbr(i * nbr);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
    }