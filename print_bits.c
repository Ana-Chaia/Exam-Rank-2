/* Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------
Write a function that takes a byte, and prints it in binary WITHOUT A NEWLINE
AT THE END.
Your function must be declared as follows:
void    print_bits(unsigned char octet);
Example, if you pass 2 to print_bits, it will print "00000010" */

#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int i = 8; // cada byte tem 8 bits;
    unsigned char eachbit;

    while (i--) // loop decrescente que controla o acesso e manipulação de cada bit individual de um byte, but also ensures that the loop runs as long as i is greater than 0 -> VER OBS 1;
    {
        eachbit = (octet >> i & 1) + '0';  // (octet >> 7) desloca o bit mais significativo (o mais à esquerda) à direita (right shift), para que possa ser facilmente testado ou manipulado; (& 1) a operação AND vai comparar o bit (agora) menos significativo ao '1' e determinar o bit final -> VER OBS 2; (+ '0') converte o '0'ou o '1' em caractere ASCII, pois o resultado de toda operação é um inteiro;
        write(1, &eachbit, 1);  // imprime cada bit como um caractere;
    }
}

/* A função print_bits processa cada bit do byte, começando do bit mais significativo (o bit na posição mais à esquerda) 
até o bit menos significativo (o bit na posição mais à direita). O loop decrementa i de 7 a 0, efetivamente percorrendo 
cada bit do byte e usando o deslocamento à direita seguido de uma operação de máscara com 1 (& 1) para isolar cada bit. 
Cada bit isolado é então convertido em um caractere '0' ou '1' e impresso. */

/* Um byte é a unidade básica de armazenamento de dados em sistemas de computação e, na maioria dos sistemas modernos, consiste em 8 bits. 
Cada bit (abreviação de binary digit) pode ter um de dois valores: 0 ou 1. Portanto, um byte pode representar até 
2 elevado a 8 =256 valores diferentes, variando de 0 a 255 em decimal.

OBS 1: (i) é inicializado com 8, que é o número total de bits em um byte.
Condição do Loop: (i--) é uma expressão que realiza duas operações:
1) Avalia i no contexto da condição do loop.
2) Decrementa i por 1.
Aqui está o que acontece em detalhes: Na primeira verificação da condição do loop, i é 8. A condição verifica i, e então i é decrementado para 7.
O loop continua enquanto o valor de i após o decremento for maior que 0. Quando i é decrementado de 1 para 0, a expressão i-- avalia como 0 (porque o valor de i antes do decremento é 1), o que é falso, e assim o loop termina.
Por Que Parar no 0
O loop está projetado para executar 8 iterações, uma para cada bit, de 7 a 0 (que correspondem às posições dos bits em um byte). Ele usa o padrão de zero-indexação típico em programação, onde o índice começa em 0 e vai até N-1
(aqui, N é 8, então N-1 é 7). O uso de i-- na condição garante que o loop execute o corpo com i começando de 7 e terminando em 0, cobrindo todas as posições de bit no byte. E não continue após o 0. */

/* OBS 2: por que a operação AND (& 1) é feita com 1?
A operação AND realizada com o número '1' é uma técnica comum para isolar ou verificar um bit específico dentro de um byte ou palavra. Essa técnica é especialmente útil quando você quer determinar se um determinado bit em uma 
posição específica é 0 ou 1. Quando você realiza uma operação AND bit a bit entre um número e o valor 1, o resultado é determinado pela seguinte regra simples da operação AND:
1 AND 1 = 1
0 AND 1 = 0
Isso significa que qualquer bit que seja AND com 1 mantém seu valor original, enquanto qualquer bit que seja AND com 0 resulta em 0. Portanto, ao fazer AND de um número com 1, você está efetivamente filtrando o valor do bit
menos significativo do número - (seu valor real, original); */