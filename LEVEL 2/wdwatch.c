/* Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.
If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.
If the number of arguments is not 2, the program displays a \n.
Examples:
$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$ */

#include <unistd.h>

int main (int argc, char const *argv[])
{
    int i = 0;
    int j = 0;

    if (argc == 3)
    {
        while (argv[2][j])
        {
            if (argv[1][i] == argv[2][j])
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
        {
            i = 0;
            while (argv[1][i])
            {
                write(1, &argv[1][i], 1);
                i++;
            }
        }   
    }
    write(1, "\n", 1);
}