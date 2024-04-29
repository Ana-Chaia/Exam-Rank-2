/* Assignment name  : swap_bits
Expected files   : swap_bits.c
Allowed functions:
--------------------------------------------------------------------------------
Write a function that takes a byte, swaps its halves (like the example) and
returns the result.
Your function must be declared as follows:
unsigned char swap_bits(unsigned char octet);
Example:
  1 byte
_____________
0100 | 0001 
     \/
     /\ 
0001 | 0100 */


unsigned char swap_bits(unsigned char octet)
{
    return ((octet >> 4) | (octet << 4));
}
/* Deslocamento à Direita (octet >> 4):
(octet >> 4) desloca todos os bits do byte octet quatro posições para a direita.
Isso tem o efeito de mover os quatro bits mais significativos (os primeiros quatro bits da esquerda) para as posições dos quatro bits menos significativos (os últimos quatro bits da direita).
Por exemplo, se octet for abcd efgh (onde a-h representam bits individuais), então (octet >> 4) resultaria em 0000 abcd.

Deslocamento à Esquerda (octet << 4):
(octet << 4) desloca todos os bits do byte octet quatro posições para a esquerda.
Isso descarta os quatro bits mais significativos e move os quatro bits menos significativos para as posições dos quatro bits mais significativos.
O resultado desse deslocamento é efgh 0000, onde os quatro bits originais mais à direita agora ocupam as quatro posições mais à esquerda.

Operação OR (|):
A operação | (OR bit a bit) é usada para combinar os dois resultados dos deslocamentos.
Cada bit no resultado final é 1 se qualquer um dos bits correspondentes nos operandos é 1. Caso contrário, é 0.
Aplicando OR a 0000 abcd e efgh 0000, obtemos efgh abcd.
Portanto, ((octet >> 4) | (octet << 4)) efetivamente troca os quatro bits da frente com os quatro de trás no byte. */