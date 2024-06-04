#include <stdio.h>
#include <stdlib.h>

void pgcd(int a, int b)
{
    int n;

    n = (a < b) ? a : b;
    while (n > 0)
    {
        if(a % n == 0 && b % n == 0)
        {
            printf("%d", n);
            return;
        }
        --n;
    }
}

int main(int ac, char **av)
{
    if(ac == 3)
        pgcd(atoi(av[1]) && atoi(av[2]));
    printf("\n");
    return(0);
}