#include <stdio.h>

#define MAX_SIZE 100 // Максимальный размер массива

// Функция для проверки, является ли число простым
int is_prime(int num) {
    if (num <= 1) return 0; // Числа <= 1 не являются простыми
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Не простое
    }
    return 1; // Простое
}

// Функция для вычисления среднего арифметического
double calculate_average(int array[], int size) {
    if (size == 0) return 0; // Избегаем деления на ноль
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    return (double)sum / size;
}

int main() {
    int X[MAX_SIZE] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int n = 15;
    int Y[MAX_SIZE];
    int k = 0; // Индекс для массива Y

    // Копирование каждого второго элемента из X в Y
    for (int i = 1; i < n; i += 2) {
        Y[k++] = X[i];
    }

    // Подсчет простых чисел в массиве X
    int prime_count_X = 0;
    for (int i = 0; i < n; i++) {
        if (is_prime(X[i])) {
            prime_count_X++;
        }
    }

    // Подсчет простых чисел в массиве Y
    int prime_count_Y = 0;
    for (int i = 0; i < k; i++) {
        if (is_prime(Y[i])) {
            prime_count_Y++;
        }
    }

    // Вычисление средних арифметических
    double average_X = calculate_average(X, n);
    double average_Y = calculate_average(Y, k);

    // Вывод результатов
    printf("Количество простых чисел в X: %d\n", prime_count_X);
    printf("Количество простых чисел в Y: %d\n", prime_count_Y);
    printf("Среднее арифметическое X: %.2f\n", average_X);
    printf("Среднее арифметическое Y: %.2f\n", average_Y);

    return 0;
}
