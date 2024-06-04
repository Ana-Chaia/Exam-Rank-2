/* Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following function:
void sort_int_tab(int *tab, unsigned int size);
It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.
Doubles must be preserved.
Input is always coherent. */

void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0; // define o índice i para começar do início do array;
    int temp;

    while(i < (size - 1)) // loop continua enquanto i for menor que size - 1. Isso garante que você não tente acessar uma posição fora do array, uma vez que você compara tab[i] e tab[i + 1];
    {
        if(tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0; // após realizar a troca, o índice i é resetado para 0. Isso é feito para garantir que o array seja percorrido novamente desde o início para verificar se mais trocas são necessárias devido à alteração dos elementos;
        }
        else
            i++; //se não for necessária uma troca entre tab[i] e tab[i + 1], incrementa-se i para verificar o próximo par de elementos;
    }
}
/* 
A abordagem utilizada na função é interessante porque garante que qualquer troca irá resultar em uma nova verificação completa do array
desde o início, o que pode ser útil para garantir a ordenação com um número menor de passagens completas do que um bubble sort típico. 
No entanto, isso pode também levar a muitas repetições desnecessárias do início do array, especialmente se a maioria das trocas ocorrer
perto do final do array. Isso torna este método menos eficiente do que outros algoritmos de ordenação como o insertion sort ou o quicksort,
especialmente para arrays grandes. */