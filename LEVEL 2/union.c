/* Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.
The display will be in the order characters appear in the command line, and
Exam Rank 02
23
will be followed by a \n.
If the number of arguments is not 2, the program displays \n.
Example:
$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$> */


#include <unistd.h>

int check(int c, char *str, int index)
{
    int i = 0;
    while (i < index)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (argc == 3)
    {
        while (argv[1][i])
            i++;
        while (argv[2][j])
        {    
            argv[1][i] = argv[2][j];
            i++;
            j++;
        }
        i--;
        while (k <= i)
        {
            if(check(argv[1][k], argv[1], k) == 1)
                write(1, &argv[1][k], 1);
            k++;
        }
    }
    write(1, "\n", 1);
}