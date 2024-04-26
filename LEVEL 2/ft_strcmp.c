//Assignment name  : ft_strcmp
//Expected files   : ft_strcmp.c
//Allowed functions:
//--------------------------------------------------------------------------------
//Reproduce the behavior of the function strcmp (man strcmp).
//Your function must be declared as follows:
//int    ft_strcmp(char *s1, char *s2);

int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

//Retorno: Quando o loop termina, pelo menos um dos seguintes casos é verdadeiro: um dos caracteres não é igual ao outro, ou uma das strings chegou ao fim. 
//A função retorna a diferença entre os valores ASCII dos caracteres onde os ponteiros s1 e s2 pararam. Isso pode indicar:
//Se *s1 - *s2 é zero, as strings são iguais.
//Se *s1 - *s2 é positivo, o caractere em s1 é lexicograficamente maior que o de s2.
//Se *s1 - *s2 é negativo, o caractere em s1 é lexicograficamente menor que o de s2.
