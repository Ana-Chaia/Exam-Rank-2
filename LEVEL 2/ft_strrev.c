//Assignment name  : ft_strrev
//Expected files   : ft_strrev.c
//Allowed functions:
//--------------------------------------------------------------------------------
//Write a function that reverses (in-place) a string.
//It must return its parameter.
//Your function must be declared as follows:
//char    *ft_strrev(char *str);

char    *ft_strrev(char *str)
{
    int lenght = 0;
    int i = -1;    //inicializado com -1 para uso em um loop onde será pré-incrementado;
    char temp;

    while (str[lenght])
        lenght++;
    while (++i < lenght / 2) //incrementa i++ antes de cada checagem do loop. Por isso, i tem que começar em -1, para ser 0 na primeira iteração, a posição certa do primeiro char na string (str[0]);
    {             //length / 2: O loop vai até a metade da string. Como a inversão de caracteres é simétrica em relação ao centro, não há necessidade de ir além da metade;
        temp = str[i];
        str[i] = str[lenght - 1 - i];
        str[lenght - 1 - i] = temp;
    }
    return (str);
}
//****A diferença entre retornar (str) e (*str) em uma função em C:
//return (str): retorna um ponteiro para char. significado: Ao retornar str, você está retornando um ponteiro para o primeiro caractere da string. 
//Isso é útil quando você quer permitir que a função que chama tenha acesso à string inteira, começando do primeiro caractere. 
//Em funções que modificam strings, como ft_strrev, retornar o ponteiro para a string modificada permite que o chamador continue a usar a string originalmente passada, que agora está invertida.
//return (*str): tipo: retorna um char. significado: Ao retornar *str, você está desreferenciando o ponteiro e retornando o valor do caractere localizado na posição para a qual str aponta,
//ou seja, o primeiro caractere da string. Isso seria usado em contextos onde apenas o caractere inicial é relevante para o chamador, o que não é comum em funções destinadas a trabalhar 
//com strings inteiras ou manipular strings de forma mais abrangente.

//ponteiro para a string (return str;) XXX um caractere único (return *str;)