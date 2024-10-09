#include <stdio.h>
#include <string.h>

//функция для вывода шестнадцатеричного представления числа
void to_hexadecimal(unsigned int a) {
    
    char binary[33]; 
    binary[32] = '\0'; 
    int index = 31;
    while (index >= 0) {
        binary[index] = (a % 2) ? '1' : '0';
        a /= 2;
        index--;
    }
    printf("Двоичное представление по тетрадам: ");
    for (int i = 0; i < 32; i++) {
        printf("%c", binary[i]);
        if ((i + 1) % 4 == 0 && i != 31) {
            printf(" ");  //разделяем по тетрадам
        }
    }
    printf("\n");

    printf("Шестнадцатеричное представление: ");
    for (int i = 0; i < 32; i += 4) {
        char tetra[5];
        strncpy(tetra, &binary[i], 4);
        tetra[4] = '\0';

        int decimal_value = (int)strtol(tetra, NULL, 2); //преобразуем тетраду в десятичное число
        printf("%X", decimal_value); 
    }
    printf("\n");
}

int main() {
    unsigned int a;

    printf("Введите положительное целое число: ");
    scanf("%u", &a);

    to_hexadecimal(a);
    
    return 0;
}
