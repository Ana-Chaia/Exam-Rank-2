//Assignment name : ft_strspn
//Expected files  : ft_strspn.c
//Allowed functions: None
//---------------------------------------------------------------
//Reproduce exactly the behavior of the strspn function
//(man strspn).
//The function should be prototyped as follows:
//size_t  ft_strspn(const char *s, const char *accept);


size_t ft_strspn(const char *s, const char *accept)
{
    size_t i = 0;
    size_t j;
    int found;

    //loop externo: percorre cada caractere de s;
    while (s[i] != '\0') 
    {
        found = 0;  //reset a cada iteração;
        j = 0;      //reseta j para começar do início de accept;
        while (accept[j] != '\0') //loop interno: verifica se s[i] está em accept;
        {
            if (s[i] == accept[j]) 
            {
                found = 1;  //se encontrado, sair do loop interno;
                break;
            }
            j++;  //se não encontrado, continua incrementando j para verificar o próximo caractere em accept;
        }
        if (!found)
            return i;  //quando/se não encontrado s[i] em nenhum caractere de accept, já retorna o índice do primeiro caractere não aceito s[i];
        i++;  //caso tenha sido encontrado algum, incrementa i para verificar o próximo caractere em s;
    }
    return i;  //retorna o comprimento de s se todos os caracteres foram encontrados em accept;
}


//A função strspn calcula o comprimento do segmento inicial de s1 que consiste somente em caracteres que estão também em s2.
//Comportamento: Retorna o comprimento do segmento contínuo no começo de s1 onde cada caractere aparece em s2. Se o primeiro caractere de s1 não estiver em s2, strspn retorna 0.