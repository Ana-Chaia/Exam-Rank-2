int     max(int* tab, unsigned int len)
{
    int i = 0;
    int result = 0;

    if(len == 0)
        return (0);
    result = tab[i];
    while (i < len)
    {
        if(result < tab[i])
            result = tab[i];
        i++;
    }
    return (result);
}