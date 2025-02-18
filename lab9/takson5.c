
#include <stdio.h>
#include <stdlib.h>

void sortRows(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            for (int k = j + 1; k < cols; k++) {
                if (matrix[i][j] > matrix[i][k]) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[i][k];
                    matrix[i][k] = temp;
                }
            }
        }
    }
}

int hasZero(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) return 1;
        }
    }
    return 0;
}

double calculateAverage(int **matrix, int rows, int cols) {
    double sum = 0;
    int totalElements = rows * cols;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / totalElements;
}

void swapDiagonals(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        int temp = matrix[i][i];
        matrix[i][i] = matrix[i][size - i - 1];
        matrix[i][size - i - 1] = temp;
    }
}

int main() {
    int rows, cols;
    printf("Введите количество строк и столбцов матрицы: ");
    scanf("%d %d", &rows, &cols);

    //выделение памяти для матрицы
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    //ввод элементов матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
 
    //сортировка строк матрицы по возрастанию
    sortRows(matrix, rows, cols);

    //проверка на наличие нулей
    if (hasZero(matrix, rows, cols)) {
        printf("Матрица содержит нули.\n");
    } else {
        printf("Матрица не содержит нулей.\n");
    }

    //вычисление среднего арифметического элементов
    double average = calculateAverage(matrix, rows, cols);
    printf("Среднее арифметическое элементов матрицы: %.2f\n", average);

    //замена главной и побочной диагоналей, если матрица квадратная
    if (rows == cols) {
        swapDiagonals(matrix, rows);
        printf("Матрица после замены главной и побочной диагоналей:\n");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("Замена диагоналей невозможна, так как матрица не квадратная.\n");
    }
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
