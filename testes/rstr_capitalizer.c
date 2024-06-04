#include <unistd.h>

void    rstr_cap(char *str)
{
    int i = 0;
    int j = 0;
    
    while(str[i] == ' ' || str[i] == '\t')
    {
        i++;
        j = i;
    }
    while (str[j])
    {
        if(str[j] >= 'A' && str[j] <= 'Z')
            str[j] = str[j] + 32;
        if((str[j] >= 'a' && str[j] <= 'z') && (str[j + 1] == '\t' || str[j + 1] == ' ' || str[j + 1] == '\0'))
            str[j] = str[j] - 32;
        write(1, &str[j], 1);
        j++;
    }
}

int main (int ac, char **av)
{
    int i = 1;

    if (ac >= 2)
    {
        while(i < ac)
        {
            rstr_cap(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}