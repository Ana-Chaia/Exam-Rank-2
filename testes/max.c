//#include <stdio.h>

int max(int* tab, unsigned int len)
{
    int max;
    int i;

    if(len == 0)
        return (0);
    max = tab[i];
    while (i < len)
    {
        if (max < tab[i])
            max = tab[i];
        i++;
    }
    return (max);
}
/* 
int main ()
{
int tab[] = {1, 2, 3, 5};
unsigned int len = 4;

printf("%d", max(tab, len));
}  */