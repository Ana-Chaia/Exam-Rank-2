/* Um número primo é um número natural maior que 1 que não possui divisores positivos outros além de 1 e ele mesmo. 
Em outras palavras, um número é considerado primo se ele não pode ser formado pela multiplicação de dois números 
menores naturais de forma que ambos sejam maiores que 1.

Únicos Divisores: Os únicos números que dividem um número primo de forma exata (ou seja, sem deixar resto) são o 
número 1 e o próprio número primo.
Não Compostos: Números que não são primos são chamados de números compostos, o que significa que eles podem ser 
divididos de forma exata por pelo menos um número natural além de 1 e eles mesmos.
Infinitude: Há uma quantidade infinita de números primos. Esta é uma descoberta antiga feita por Euclides por volta 
de 300 a.C. e é uma das afirmações mais importantes na teoria dos números.
Exemplos: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, ... e assim por diante.

Número 2 É o único número primo par. Todos os outros números primos são ímpares, já que qualquer número par maior 
que 2 pode ser dividido por 2.
Testes de Primalidade: Existem diversos métodos para testar se um número é primo, desde divisões sucessivas 
(método simples e direto) até algoritmos mais avançados e eficientes, como o teste de primalidade de Miller-Rabin, 
que é usado para números muito grandes. */


#include <stdio.h>

int ft_atoi(char *s)
{
    int res = 0;

    while (*s)
        res = res * 10 + *s++ - '0';
    return (res);
}

int is_prime(int num)
{
    int i = 2;
    
    if (num <= 1)
        return (0);
    while (i * i <= num)
    {
        if (num % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void put_nbr(int n)
{
    if (n > 9)
        put_nbr(n / 10);
    char digit = n % 10 + '0';
    write(1, &digit, 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int nbr = ft_atoi(argv[1]);
        int sum = 0;

        while (nbr > 0)
        {
            if (is_prime (nbr))
                sum += nbr;
            nbr--;
        }
        put_nbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}