//Assignment name : ft_strcspn
//Expected files  : ft_strcspn.c
//Allowed functions: None
//---------------------------------------------------------------
//Reproduce exactly the behavior of the function strcspn
//(man strcspn).
//The function should be prototyped as follows:
//size_t  ft_strcspn(const char *s, const char *reject);


size_t  ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    size_t j;

    while (s[i]) //itera sobre cada caractere da string s;
    {
        j = 0; //é necessário reiniciar j para verificar cada caractere de s, desde o início da string reject;
        while (reject[j])
        {
            if(s[i] == reject[j])
                return (i);
            j++;
        }
        i++
    }
    return (i);
}

//Essencialmente, ft_strcspn funciona medindo o comprimento de uma substring de s que não contém qualquer caractere especificado em reject. 
//Se nenhum caractere de reject for encontrado em s, ela retorna o comprimento total de s, indicando que toda a string é composta por caracteres não listados em reject.
