#include <stdlib.h>

char *ft_strncpy(char *s1, char *s2, int n)
{
    int i = 0;

    while(i < n && s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return(s1);
}

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int word_count = 0;

    while(str[i])
    {
        if(!is_space(str[i]))    // condição: se o primeiro char não for espaço;
        {
            word_count++;           // pois achamos a primeira palavra;
            while(str[i] && !is_space(str[i]))      // roda até achar o fim da palavra;
            i++;
        }
        else
            i++;      // pois, se for espaço, roda até encontrar o que não é;
    } // esse while serve para contar o número de palavras que haverá no array;
    char **words = (char**)malloc(sizeof(char*) * (word_count + 1)); // aloca memória para o array de palavras;
    i = 0;
    while(str[i])
    {
        if(!is_space(str[i])) // condição: se o primeiro char não é espaço, novamente;
        {
            int j = i; // para salvar a posição do primeiro char da palavra;
            while(str[i] && !is_space(str[i])) // roda até achar o fim da palavra;
                i++;
            words[k] = char*(malloc(sizeof(char) * (i - j + 1))) // aloca memória para a palavra;
            ft_strncpy(words[k++], &str[j], i - j); // The use of post-increment (k++) means that the function uses the current value of k for indexing during the function call and then increments k by 1. This way, after the function call, k is ready to point to the next empty slot in the out array for the subsequent word.
        }
        else
            i++;
    }
    words[k] = NULL; // para marcar o fim do array de palavras;
    return(words);
}

