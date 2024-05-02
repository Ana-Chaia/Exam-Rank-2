#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int flag;

    if(argc ==2)
    {
        while(argv[1][i] == ' '|| argv[1][i] == '\t')
            i++;
        while(argv[1][i])
        {
            if(argv[1][i] == ' ' || argv[1][i] == '\t')
                flag = 1;
            else
            {
                if(flag == 1)
                    write(1, "   ", 3); // incluir 3 espaços entre as palavras;
                flag = 0;
                write(1, &argv[1][i], 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}