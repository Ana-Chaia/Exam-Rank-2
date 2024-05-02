/* Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------
Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.
The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".
Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".
Minus signs ('-') are interpreted only if they are the first character of the
string.
Your function must be declared as follows:
int ft_atoi_base(const char *str, int str_base); */

char to_lower(char c)
{
    if(c >= 'A' && c <= 'Z')
        return (c + 32);
    return (c);
}

int get_digit(char c, int digitsbase)
{
    if (c >= '0' && c < '0' + digitsbase) // verifica se o caractere c está entre '0' e o limite superior para dígitos numéricos na base especificada;
        return (c - '0'); // subtraindo '0' do caractere transforma o valor ASCII do dígito numérico em seu equivalente inteiro (por exemplo, '0' se torna 0);
    else if (c >= 'a' && c < 'a' + digitsbase - 10) // verifica se o caractere c está entre 'a' e o limite superior para letras usadas em bases numéricas maiores que 10. A condição - 10 ajusta o intervalo para começar depois dos primeiros 10 dígitos numéricos;
        return (c - 'a' + 10); // a subtração de 'a' ajusta 'a' para 0, e adicionar 10 converte isso para o valor numérico apropriado (por exemplo, 'a'/0 se torna 10);
    else
        return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int result = 0;
    int sign = 1;
    int digit;

    if (*str == '-')
    {
        sign = -1;
        ++str;
    }
    while ((digit = get_digit(to_lower(*str), str_base)) >= 0)
    { 
        result = result * str_base + digit * sign;
        ++str; // enquanto a função get_digit retorna um valor válido para o dígito (não -1), multiplica o resultado acumulado pela base e adiciona o novo dígito ajustado pelo sinal;
    }
    return (result);
}