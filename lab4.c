/*Написать функции, вычисляющие периметр и площадь треугольника по значе-ниям длин трёх его сторон. Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычис-ленные с помощью написанных функций значения его периметра и площади. */
#include "sours.h"
#include <stdbool.h>

bool check(int a, int b, int c){
    return (a+b>c && c+b>a && a+c>b);}

int perimetr(int a, int b, int c){
    return a + b + c;}

double square(double a, double b, double c){
    return ((a+b+c)/2 * ((a+b+c)/2 - a) * ((a+b+c)/2 - b) * ((a+b+c)/2 - c));}



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "sours.h"

int main(){
    double s;
    int a, b, c, p;

    printf("input:");
    scanf("%d %d %d", &a, &b, &c);

    if (check(a, b, c)){
        p = perimetr(a, b, c);
        s = sqrt(square(a, b, c));
        printf("perimetr: %d\n", p);
        printf("square: %.2lf", s);}
    else {printf("Error");}
    return 0;}

