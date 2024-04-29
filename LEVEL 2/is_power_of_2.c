//Assignment name  : is_power_of_2
//Expected files   : is_power_of_2.c
//Allowed functions: None
//--------------------------------------------------------------------------------
//Write a function that determines if a given number is a power of 2.
//This function returns 1 if the given number is a power of 2, otherwise it returns 0.
//Your function must be declared as follows:

//int     is_power_of_2(unsigned int n);

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return (0);
    while (n % 2 == 0) //verifica o resto da divisão de n por 2. Se o resultado é 0, isso significa que n é par, ou seja, divisível por 2 sem deixar resto. Em termos de bits, isso também indica que o bit menos significativo de n é 0;
        n /= 2;   //divide n por 2 e atribui o resultado de volta a n. Dividir por 2 em aritmética binária é equivalente a deslocar todos os bits de n uma posição para a direita. Por exemplo, se n for 8 (binário: 1000), após n /= 2, n será 4 (binário: 0100). Esta operação efetivamente descarta o bit menos significativo de n a cada iteração;
    return ((n ==1) ? 1 : 0); //esta expressão é uma condição ternária que verifica se n é igual a 1. Se sim, retorna 1 (verdadeiro), indicando que o número original era uma potência de dois. Se não, retorna 0 (falso);
}
//Memory and Storage: Computer memory and storage capacities (like RAM and disk sizes) are typically measured in powers of two. For example, 512 MB, 1 GB (gigabyte), 2 GB, etc., where 1 GB technically equals 2/30 bytes (1,073,741,824 bytes) //- dois elevado a trinta;

//Data Alignment and Addressing: Powers of two are used for efficient memory alignment and addressing, which can enhance performance by aligning data structures at address boundaries that are multiples of powers of two;

//Bitwise Operations: Powers of two play a role in bitwise operations, where individual bits can be manipulated directly. These operations are often used for setting, clearing, and toggling specific bits within data structures, commonly seen in low-level programming;

//Algorithmic Efficiency: Many algorithms, especially those dealing with data structures like binary trees, heaps, or for performing tasks such as hashing, use powers of two to optimize calculations and memory usage;

// Characteristics: A number that is a power of two has exactly one bit set in its binary representation. For example, the binary representation of 16 (2/4) - dois elevado a quatro - is 10000;
//Powers of two are closely related to logarithms base two. The binary logarithm (log base 2) of a power of two number 2/𝑛 is 𝑛


