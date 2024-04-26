//Assignment name  : ft_atoi
//Expected files   : ft_atoi.c
//Allowed functions: None
//--------------------------------------------------------------------------------
//Write a function that converts the string argument str to an integer (type int)
//and returns it.
//It works much like the standard atoi(const char *str) function, see the man.
//Your function must be declared as follows:
//int ft_atoi(const char *str);


int ft_atoi(char *str)
{
    int final = 0;
    int intsign = 1;

    while (*str == ' ' || (*str >= 9 && *str <= 13)) //espaços em branco (' ') ou chrs de controle como tabulações e novas linhas (ASCII 9 a 13)
        str++;
    while (*str == '-')
        intsign = -1;
    while (*str == '+' || *str == '-')
        str++;
    while (*str >= '0' && *str <= '9')
        {
            final = final * 10 + *str - '0'; //o n. é construído digito a digito. final * 10 desloca o n. uma posição decimal para a esquerda, e *str - '0' converte o char do dígito em seu valor numérico(int) correspondente, que é então adicionado a final; Após, str++ apontar para o próximo char;
            str++;
        }
    return (final * intsign);
}