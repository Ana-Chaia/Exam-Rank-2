/* Assignment name  : ft_rrange
Expected files   : ft_rrange.c
Allowed functions: malloc
--------------------------------------------------------------------------------
Write the following function:
int     *ft_rrange(int start, int end);
It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array.
Examples:
- With (1, 3) you will return an array containing 3, 2 and 1
- With (-1, 2) you will return an array containing 2, 1, 0 and -1.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing -3, -2, -1 and 0. */


#include <stdlib.h>

int ft_rrange(int start, int end)
{
    int len = abs(end - start) +1; // len calcula o número de elementos no intervalo. abs(end - start) dá a diferença absoluta entre end e start, garantindo um valor positivo. O +1 garante que ambos os extremos, start e end, estejam incluídos no intervalo.
    int i = 0;
    int *range;

    range = (int*)malloc(sizeof(int) * len);
    while (i < len)
    {
        range[i] = end;
        end = start < end ? end - 1 : end + 1;
        i++;
    }
    return (range);
}