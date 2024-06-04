/* Assignment name  : max
Expected files   : max.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following function:
int     max(int* tab, unsigned int len);
The first parameter is an array of int, the second is the number of elements in
the array.
The function returns the largest number found in the array.
If the array is empty, the function returns 0. */

//#include <stdio.h>

int max(int* tab, unsigned int len) //int *tab: um ponteiro para o array de inteiros;
{
    int result; // variável usada para armazenar o maior valor encontrado durante a iteração no array;
    unsigned int i = 0;

    if (len == 0)  // indica que o array está vazio - a função retorna 0;
        return (0);
    result = tab[i]; // inicializa result com o primeiro elemento do array; Assumindo que len é maior que zero, este é um ponto de partida válido para encontrar o máximo;
    while (i < len) // itera sobre todos os elementos do array. O loop começa do índice 0 e continua até que i seja menor que len;
    {
        if (result < tab[i]) // dentro do loop, a função verifica se o valor armazenado em result é menor que o elemento atual do array (tab[i]) - na primeira rodada, sempre será o mesmo;
            result = tab[i]; // quando/se result for menor, atualiza result para esse novo valor maior;
        i++; // move para checar o próximo elemento do array;
    }
    return (result);
}


/* int main ()
{
int tab[] = {1, 2, 3, 5};
unsigned int len = 4;

printf("%d", max(tab, len));
} */