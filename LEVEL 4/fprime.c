Assignment name  : fprime
/* Expected files   : fprime.c
Allowed functions: printf, atoi
--------------------------------------------------------------------------------
Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.
Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.
If the number of parameters is not 1, simply display a newline.
The input, when there is one, will be valid.
Examples:
$> ./fprime 225225 | cat -e
3*3*5*5*7*11*13$
$> ./fprime 8333325 | cat -e
3*3*5*5*7*11*13*37$
$> ./fprime 9539 | cat -e
9539$
$> ./fprime 804577 | cat -e
804577$
$> ./fprime 42 | cat -e
2*3*7$
$> ./fprime 1 | cat -e
1$
$> ./fprime | cat -e
$
$> ./fprime 42 21 | cat -e
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int number;

    if(argc == 2)
    {
        i = 1;
        number = atoi(argv[1]);
        if(number == 1)
            printf("1"); // porque 1 não tem fatores primos;
        while(number >= i++) // incrementa i começando de 2, e continua enquanto i for menor ou igual ao number. Isso garante que todos os possíveis fatores de number sejam verificados;
        {
            if(number % i == 0) //verifica-se se number é divisível por i sem deixar resto (number % i == 0). Se verdadeiro, i é um fator de number;
            {
                printf("%d", i); //se i é um fator, ele é impresso;
                if(number == i) //e number é igual a i, significa que o último fator primo foi encontrado, então o loop é interrompido com break;
                    break;
                printf("*");
                number = number / i; //number é dividido por i, efetivamente reduzindo-o pelo fator encontrado;
                i = 1; // i é resetado para 1 para começar a verificar novamente a partir do menor divisor possível (2);
            }
        }
    }
    printf("\n");
    return(0);
}