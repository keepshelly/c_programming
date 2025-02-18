#ifndef PARABOLA_H
#define PARABOLA_H

#include <math.h>
typedef struct {
    double a;
    double b;
    double c;
} Parabola;

//прототип
double calculate_min(Parabola p);

#endif // PARABOLA_H