#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// 11 ВАРИАНТ

int main(){
        float x;
        float y;
        printf("Принадлежность точки к плоскости\n");
        printf("Введите координаты точки X\n");
        scanf("%f",&x);
        printf("Введите координаты точки Y\n");
	scanf("%f",&y);
	if ((x <= 1.0 && x >= 0 && y >= -2.0 && y <= 0) || (x >= -1.8 && x <= 0 && y >= -2.0 && y <= 0) || ( x >= -1.8 && x <= -1.0 && y <= 1.0 && y>=0) || (x >= -1 && x <=0 && y == fabs(x))){
                printf("Точка лежит на плоскости");
}
	else
{
	printf("Точка вне плоскости\n");
}
}
