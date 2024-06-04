
/* Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------
Write a program that takes two strings representing two strictly positive
integers that fit in an int.
Display their highest common denominator followed by a newline (It's always a
strictly positive integer).
If the number of parameters is not 2, display a newline.
Examples:
$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e
1$
$> ./pgcd | cat -e
$ */

// O programa é um exercício típico de encontrar o maior divisor comum (GCD) entre dois números inteiros positivos, utilizando a entrada da linha de comando.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const **argv)
{
    int nbr1; // declaração de duas variáveis int que serão usadas para armazenar os dois números fornecidos através da linha de comando;
    int nbr2;

    if( argc == 3)
    {
        if((nbr1 = atoi(argv[1])) > 0 && (nbr2 = atoi(argv[2])) > 0) // atoi converte os argumentos da linha de comando de strings para inteiros; também verifica se ambos os números são estritamente positivos, como requerido;
        {
            while(nbr1 != nbr2)
            {
                if(nbr1 > nbr2)
                    nbr1 = nbr1 - nbr2;
                else
                    nbr2 = nbr2 - nbr1;
            }
            printf("%d", nbr1); // quando o laço termina (quando nbr1 é igual a nbr2), qualquer um dos dois pode ser usado para imprimir o GCD, pois ambos serão o mesmo número;
        }
    }
    printf("\n");
    return (0);
}

//The GCD (Greatest Common Divisor) of two numbers a and b is the largest positive integer that divides both a and b without leaving a remainder. It is not necessarily the smallest number, but it is always less than or equal to the smaller of the two numbers.
// By starting with the smaller number, the maximum number of iterations is minimized. This approach improves efficiency while maintaining correctness, as the GCD will be found correctly within the fewer possible iterations. The GCD is always less than or equal to the smallest number among the inputs, hence starting with the smallest number is optimal. 

#include <stdio.h>
#include <stdlib.h>

void pgcd(int a, int b)
{
    int n = (a < b) ? a : b; // Start with the smaller number

    while (n > 0)
    {
        if (a % n == 0 && b % n == 0)
        {
            printf("%d", n);
            return;
        }
        --n;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        pgcd(atoi(argv[1]), atoi(argv[2]));

    printf("\n");
    return (0);
}
