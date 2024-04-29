/* Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, reverses it, bit by bit (like the
example) and returns the result.
Your function must be declared as follows:
unsigned char   reverse_bits(unsigned char octet);
Exam Rank 02
21
Example:
  1 byte
_____________
 0010  0110
     ||
     \/
 0110  0100 */


unsigned char reverse_bits(unsigned char octet)
{
    unsigned char reversed = 0;
    int i = 8;

    while (i > 0)
    {                                // (octet % 2) obtém o bit menos significativo do octet. % é o operador de módulo que retorna o resto da divisão de octet por 2, que se tiver bit menos significativo 1, será 1, ou 0 se for 0;
        reversed = reversed * 2 + (octet % 2); // (reversed * 2) multiplicar por 2 em base binária equivale a deslocar todos os bits uma posição para a esquerda. Isso libera o bit menos significativo de reversed (o bit mais à direita), que agora está vazio (0) - para ir acumulando;
                                               // após deslocar reversed para a esquerda, o bit menos significativo está livre. A operação (octet % 2) extrai o bit menos significativo de octet, e essa soma adiciona esse bit extraído à posição menos significativa de reversed. Isso efetivamente "insere" o bit de octet na nova posição.
        octet = octet / 2; // (octet / 2) dividir por 2 em aritmética binária é equivalente a deslocar todos os bits uma posição para a direita. Isso descarta o bit menos significativo e move todos os outros bits uma posição para a direita;
        i--;
    }
    return (reversed);
}

unsigned char reverse_bits(unsigned char octer)
{
    unsigned char reversed = 0;
    int i = 8;

    while (i--)
    {
        reversed = reversed << 1; // a cada iteração do loop, todos os bits em reversed são deslocados uma posição para a esquerda. Isso abre um espaço no bit menos significativo (à direita);
        reversed |= (octer & 1); // (octer & 1 ) isola o bit menos significativo de octer (é 1 se o bit menos significativo for 1, e 0 se for 0). O operador |= faz um OR bit a bit entre reversed e o resultado de (octer & 1). Isso efetivamente insere esse bit isolado na posição menos significativa de reversed, que foi liberada pelo deslocamento à esquerda;
        octer = octer >> 1;    // desloca todos os bits em octer uma posição para a direita, efetivamente descartando o bit menos significativo e trazendo todos os outros bits uma posição para baixo;
    }
    return (reversed);
}
