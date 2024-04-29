//Assignment name  : inter
//Expected files   : inter.c
//Allowed functions: write
//Exam Rank 02
//--------------------------------------------------------------------------------
//Write a program that takes two strings and displays, without doubles, the
//characters that appear in both strings, in the order they appear in the first one.
//The display will be followed by a \n.
//If the number of arguments is not 2, the program displays \n.

#include <unistd.h>

int iter(char *str, char c, int len)
{
    int i = 0;

    while (str[i] && (i > len || len == -1)) //continua a iteração enquanto o caractere atual não for nulo e o índice i for menor que len ou len for -1 (busca sem limite);
    {
        if (str[i++] == c)
            return (1);
    }
    return (0);
}

int main (int argc, char **argv)
{
    int i;

    if (argc == 3)
    {
        i = 0;
        while (argv[1][i])
        {
           if (!iter(argv[1], argv[1][i], i) && iter(argv[2], argv[1][i], -1))
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}

//Condições:
//!iter(argv[1], argv[1][i], i): Verifica se o caractere argv[1][i] não apareceu antes na própria string (evita duplicatas).
//iter(argv[2], argv[1][i], -1): Verifica se o caractere argv[1][i] aparece em argv[2].
//Ação: Se ambas as condições são verdadeiras, escreve o caractere para a saída padrão (stdout).