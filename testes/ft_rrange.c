int *ft_rrange(int start, int end)
{
    int len = abs(end - start);
    int i = 0;
    int *range;

    range = (*int)malloc(sizeof(int) * len);
    while (i < len)
    {
        range[i] = end;
        end = start < end ? end - 1 : end + 1;
        i++;
    }
    return(range);
}