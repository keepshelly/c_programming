#include <stdio.h>
#include <stdlib.h>
#include "parabola.h"

int main() {
    int M;
    printf("Введите количество парабол (M): ");
    scanf("%d", &M);

    Parabola *parabolas = malloc(M * sizeof(Parabola));
    if (parabolas == NULL) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }
    for (int i = 0; i < M; i++) {
        printf("Введите коэффициенты a, b, c для параболы %d: ", i + 1);
        scanf("%lf %lf %lf", &parabolas[i].a, &parabolas[i].b, &parabolas[i].c);
    }

    int k = 0;
    double max_min = -INFINITY;
    int max_index = -1;

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