#include <unistd.h>

int ft_atoi(char *str)
{
    int final = 0;

    while(*str)
    {
        final = final * 10 + *str - '0';
        str++;
    }
    return(final);
}
int is_prime(int nb)
{
    int i = 2;

    if(nb <= 1)
        return (0);
    while(i * i <= nb)
    {
        if(nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}
void ft_putnbr(int n)
{
    if (n > 9)
        ft_putnbr(n / 10);
    char digit = n % 10 + '0';
    write(1, &digit, 1);
}
int main (int ac, char **av)
{
    int result = 0;
    int sum = 0;

    if (ac == 2)
    {
        result = ft_atoi(av[1]);
        while (result > 0)
        {
            if(is_prime(result))
                sum = sum + result;
            result--;
        }
        ft_putnbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}