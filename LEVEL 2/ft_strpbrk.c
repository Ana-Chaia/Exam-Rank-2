//Assignment name : ft_strpbrk
//Expected files  : ft_strpbrk.c
//Allowed functions: None
//---------------------------------------------------------------
//Reproduce exactly the behavior of the function strpbrk (man strpbrk).
//The function should be prototyped as follows:
//char    *ft_strpbrk(const char *s1, const char *s2);


char *ft_strpbrk(const char *s1, const char *s2)
{
    const char *s2_start = s2;  // salva a posição inicial de s2 para reutilização;

    if (!s1 || !s2)  // checa se algum dos ponteiros é NULL;
        return NULL;
    while (*s1)
    { 
        s2 = s2_start;  // reinicia s2 cada vez que um novo caractere de s1 é verificado;
        while (*s2)
        {
            if (*s1 == *s2)
                return (char *)s1;  // faz cast se uma correspondência é encontrada;
            s2++;  // avança para o próximo caractere de s2 se nenhuma correspondência for encontrada;
        }
        s1++;  // avança para o próximo caractere de s1 quando s2 chegou no '\0';
    }
    return NULL;  // retorna NULL se nenhuma correspondência for encontrada;
}

//The strpbrk() function locates in the null-terminated string s the first occurrence of any character in the string charset and returns a pointer to this character.
//If no characters from charset occur anywhere in s strpbrk() returns NULL. 
//Essencialmente, strpbrk procura na string principal o primeiro caractere que corresponde a qualquer um dos caracteres em uma string secundária fornecida.
//O nome sugere o propósito da função: "string point break", identificar um "ponto de quebra" dentro de uma string.