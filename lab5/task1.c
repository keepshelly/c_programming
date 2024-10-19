#include <stdio.h> //компл числа, на оценку 4
#define N 5
int max = 0;
int max_index;
int min = 0;
int min_index;
int main() {
     int A[5] = {2,4,6,8,10};
     int B[5] = {-1,-2,-3,-4,-5};
     int C[5];
     for(int i = 0; i < N; i++){
            C[i] = A[i]+B[i];
    }
    printf("Сумма целых и мнимых частей в массиве C:");
    for(int i = 0; i<N;i++){
        printf("%d ",C[i]);
    }
    for(int i = 0;i < N; i++){
        if (A[i] > 0){
            if (A[i] > max){
                max = A[i];
                max_index = i;
            }

        }
    }
    for(int i = 0;i < N; i++){
        if (B[i] < 0){
            if(B[i] < min) {
                min = B[i];
                min_index = i;
            }
        }
    }
    printf("\nМаксимальное целое:%d \nМинимальное мнимое:%d",max,min);
    printf("\nМаксимальный индеск целого:%d \nМинимальный индекс мнимого:%d",max_index,min_index);

    double sr;
    int sum = 0;
        for(int i = 0; i<N;i++){
            sum += C[i];
            sr = sum / N;
        }
        printf("\nСреднее арифметическое:%.2f",sr);
}
