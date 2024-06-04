
int ft_atoi(char *str)
{
    int result = 0;

    while(*str)
    {
        result = (result * 10) + *str - '0';
        str++;
    }
    return(result);
}

void putnbr(int n)
{
    if(n > 9)
        putnbr(n / 10);
    ft_putchar(n % 10 + '0');
}

int main(int ac, char **av)
{
    int i = 1;
    int n = 0;

    if(ac == 2)
    {
        n = ft_atoi(av[1]);
        while(n <= 9)
        {
            putnubr(i);
            write(1, " x ", 3);
            putnbr(n);
            write(1, " = ", 3);
            putnbr(i * n);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}
