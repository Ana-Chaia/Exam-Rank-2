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