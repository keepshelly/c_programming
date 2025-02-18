#include <math.h>
#include "parabola.h"
double calculate_min(Parabola p) {
    if (p.a > 0) {
        double x_min = -p.b / (2 * p.a);
        return p.a * x_min * x_min + p.b * x_min + p.c;
    } else {
        return NAN;
    }
}