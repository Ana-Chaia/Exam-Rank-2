/* Assignment name  : ft_list_foreach
Expected files   : ft_list_foreach.c, ft_list.h
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a list and a function pointer, and applies this
function to each element of the list.
It must be declared as follows:
void    ft_list_foreach(t_list *begin_list, void (*f)(void *));
The function pointed to by f will be used as follows:
(*f)(list_ptr->data);
You must use the following structure, and turn it in as a file called
ft_list.h:
typedef struct    s_list
{
struct s_list *next;
void          *data;
}             t_list;
 */


#include "ft_list.h"

void    ft_listforeach(t_list *begin_list, void (*f) (void *))
{
    t_list *temp;

    temp = begin_list;
    while(begin_list != NULL) // e NÃO (begin_list->next != NULL) -> a condição é enquanto o ponteiro não apontar para nulo, ou seja, queremos que a averificação alcanceo último nó; 
    {
        (*f)(begin_list->data);
        begin_list = begin_list->next;
    }
}
// Você deve criar uma função chamada ft_list_foreach que tem como objetivo aplicar uma função especificada
//a cada elemento de uma lista encadeada. A lista é representada por uma estrutura definida em ft_list.h, 
//e a função que você deve aplicar é passada como um ponteiro para função. 

// OBS: PRECISA ENTREGAR O ARQUIVO FT_LIST.H TAMBÉM;
/* 
typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
 */

/* 1. current != NULL
Esta condição verifica se o ponteiro current em si é nulo ou não. Usar current != NULL em um loop while garante que o loop continue enquanto houver um nó válido para processar. Isso significa que o loop irá incluir a execução de seu corpo mesmo quando current apontar para o último nó da lista, já que o último nó não é NULL.
Uso comum: Usar essa condição em um loop permite que você acesse e processe o data de cada nó, incluindo o último nó, pois você garante que current é sempre um nó válido antes de tentar acessar qualquer um de seus membros (como data ou next).

2. current->next != NULL
Esta condição verifica se o campo next do nó atual (current) é nulo. Em um loop while, isso significa que o loop irá terminar antes de current alcançar o último nó, pois para o último nó, next é NULL. Essa condição é útil quando você precisa garantir que há sempre um próximo nó disponível após o nó atual, o que é crucial em situações como inserção ou remoção de nós em posições específicas, ou quando você está comparando nós adjacentes.
Uso comum: Usar current->next != NULL é típico em algoritmos que necessitam de acessar o próximo nó após o nó atual, como em ordenação ou quando você precisa modificar a estrutura da lista sem perder o acesso ao resto da lista após o nó atual.
 */