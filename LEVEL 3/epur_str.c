/* Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.
A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.
If the number of arguments is not 1, or if there are no words to display, the
program displays \n.
Example:
$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$> */

#include <unistd.h>

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int i = 0;
        int flag; // será usada como uma flag para controlar quando espaços devem ser adicionados entre as palavras;

        while (argv[1][i] == ' ' || argv[1][i] == '\t') // avança até chegar ao primeiro caractere que não seja (' ') ou ('\t') no início da string;
            i++;
        while (argv[1][i]) // itera sobre cada caractere da string começando do primeiro caractere não-espaço, até chegar ao final da string ('\0');
        {
            if (argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1; // se o caractere atual for um espaço ou um tab, a flag é setada para 1;
            else // então, se o caractere atual não é um espaço ou tabulação;
            {
                if (flag == 1) // mas a flag estiver 1, um único espaço é escrito na saída. Assegura que apenas um espaço será adicionado entre palavras, independentemente do número de espaços ou tabulações na entrada;
                    write(1, " ", 1);
                flag = 0; // aflag é resetada para 0, e o caractere atual é escrito na saída. Isso acontece para cada caractere que não seja espaço ou tabulação;
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}