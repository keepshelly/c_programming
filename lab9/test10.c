#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//создал матрицу
int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}
//освобождение
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
//рандом числа в матрицу
void fillMatrixRandom(int** matrix, int rows, int cols, int minVal, int maxVal) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (maxVal - minVal + 1) + minVal;
        }
    }
}
void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));//генератор
    int rows, cols; //размер 5 на 5 // scanf wrong input
    int validInput = 0;

    while (!validInput) {
        printf("Введите два числа, каждое из которых должно быть 2 или больше: ");
        int result = scanf("%d %d", &rows, &cols);
        if (result != 2) {
            printf("Ошибка ввода. Пожалуйста, введите два числа.\n");
            while (getchar() != '\n');
        } else if (rows < 2 || cols < 2) {
            printf("Ошибка: числа должны быть 2 или больше.\n");
        } else {
            validInput = 1;
        }
}
    int** A = createMatrix(rows, cols);
    fillMatrixRandom(A, rows, cols, -10, 10); 
    printf("\nисходная матрица A:\n");
    printMatrix(A, rows, cols);

    //мин элемент и позишин
    int min = A[0][0];
    int minRow = 0, minCol = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] < min) {
                min = A[i][j];
                minRow = i+1;
                minCol = j+1;
            }
        }
    }
    printf("\nминимальный элемент: %d\n", min);
    printf("его позиция: строка %d, столбец %d\n\n", minRow, minCol);

    //вторая матрица с искл. строки и столбца где стоит мин элемент
    int** C = createMatrix(rows - 1, cols - 1);
    int ci = 0, cj = 0;
    for (int i = 0; i < rows; i++) {
        if (i == minRow) continue; //пропуск строки
        cj = 0;
        for (int j = 0; j < cols; j++) {
            if (j == minCol) continue; //пропуск столбца
            C[ci][cj] = A[i][j];
            cj++;
        }
        ci++;
    }
    printf("матрица C после удаления строки и столбца:\n");
    printMatrix(C, rows - 1, cols - 1);
    
    //подсчет нулей
    int zeroCount = 0;
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < cols - 1; j++) {
            if (C[i][j] == 0) zeroCount++;
        }
    }
    printf("\nколичество нулей в матрице C: %d\n", zeroCount);

    //смена первой и последней строки
    for (int j = 0; j < cols - 1; j++) {
        int temp = C[0][j];
        C[0][j] = C[rows - 2][j];
        C[rows - 2][j] = temp;
    }

    printf("\nматрица C после замены первой и последней строк:\n");
    printMatrix(C, rows - 1, cols - 1);

    //освобождаю память
    freeMatrix(A, rows);
    freeMatrix(C, rows - 1);

    return 0;
}
