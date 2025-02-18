#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
    double a;
    double b;
    double c;
} Parabola;
//вычисляю минимум у параболы
double calculate_min(Parabola p) {
    if (p.a > 0) {
        //с ветвями вверх - сущ
        double x_min = -p.b / (2 * p.a);
        return p.a * x_min * x_min + p.b * x_min + p.c;
    } else {
        //с ветвями вниз - несущ
        return NAN;
    }
}

int main() {
    int M;
    printf("Введите количество парабол (M): ");
    scanf("%d", &M);

    Parabola *parabolas = malloc(M * sizeof(Parabola));
    if (parabolas == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    //ввод коэффициентов 
    for (int i = 0; i < M; i++) {
        printf("Введите коэффициенты a, b, c для параболы %d: ", i + 1);
        scanf("%lf %lf %lf", &parabolas[i].a, &parabolas[i].b, &parabolas[i].c);
    }

    int k = 0; //счет парабол с минимумом
    double max_min = -INFINITY; //максимальный минимум
    int max_index = -1; //индекс параболы с наибольшим минимумом

    //с ф-цией которая считает параболы(вниз или вврех ветви), цикл работает на подстановку всех парабол, записанных с клавиатуры в эту ф-цию
    for (int i = 0; i < M; i++) {
        double min_value = calculate_min(parabolas[i]);
        if (!isnan(min_value)) {
            k++;
            if (min_value > max_min) {
                max_min = min_value;
                max_index = i;
            }
        }
    }

    if (k > 0) {
        printf("Количество парабол с минимумом: %d\n", k);
        printf("Парабола с наибольшим минимумом:\n");
        printf("a = %lf, b = %lf, c = %lf\n", parabolas[max_index].a, parabolas[max_index].b, parabolas[max_index].c);
        printf("Значение минимума: %lf\n", max_min);
    } else {
        printf("Нет парабол с минимумом.\n");
    }

    free(parabolas);

    return 0;
}