#include <stdio.h>
void count_bits(unsigned int a, int *zeros, int *ones) {
    *zeros = 0;
    *ones = 0;
    while (a > 0) {
        if (a & 1) {
            (*ones)++;
        } else {
            (*zeros)++;
        }
        a >>= 1;
    }
}

int main() {
    unsigned int a;
    printf("Введите неотрицательное целое число: ");
    scanf("%u", &a);
    
    int zeros, ones;
    count_bits(a, &zeros, &ones);
    
    printf("Количество единичных битов: %d\n", ones);
    printf("Количество нулевых битов: %d\n", zeros);
    
    return 0;
}
