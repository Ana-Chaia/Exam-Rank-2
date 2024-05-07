/* 
Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions:
--------------------------------------------------------------------------------
Write the following functions:
t_list  *sort_list(t_list* lst, int (*cmp)(int, int));
This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.
Duplications must remain.
Inputs will always be consistent.
You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

/* typedef struct s_list t_list;
struct s_list
{
int data;
    t_list  *next;
}; */
/* 
Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise.
For example, the following function used as cmp will sort the list
in ascending order:

int ascending(int a, int b)
{
    return (a <= b);
}
 */

#include "list.h"

t_list  *sort_list(t_list *lst, int (*cmp) (int, int))
{
    int swap; // variável swap para ajudar na troca de valores (int) entre dois nós;
    t_list *temp; // ponteiro salvar a referência do início da lista durante as iterações e poder retornar ela no final;

    temp = lst;
    while (lst->next != NULL) // a condição garante que lst não é o endereço do último nó da lista, e isso é importante pois o último nó não tem um próximo para comparar; ou resultaria em um erro de segmentação porque você estaria tentando acessar dados de um ponteiro nulo;
    {
        if(((*cmp)(lst->data, lst->next->data)) == 0) // aqui é onde a comparação acontece. Se a função cmp chamada com o dado atual (lst->data) e o dado do próximo nó (lst->next->data) retorna 0, isso indica que os valores estão na ordem errada e precisam ser trocados;
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = temp; // depois da troca, o ponteiro lst é redefinido para tmp, que é o início da lista, para começar a verificação novamente desde o início;
        }
        else
            lst = lst->next; // se os nós estão na ordem correta, o ponteiro lst simplesmente avança para o próximo nó na lista;
    }
    lst = temp; // após completar as iterações e as possíveis trocas, lst é redefinido para o início da lista novamente, garantindo que o ponteiro retornado aponte para o início da lista;
    return (lst);
}


/* 
lst->data é usado para acessar ou modificar os dados armazenados em um nó da lista (o int).
lst->next é usado para navegar para o próximo nó na lista encadeada (o ponteiro do próximo int). */

