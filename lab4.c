/*Написать функции, вычисляющие периметр и площадь треугольника по значе-ниям длин трёх его сторон. Разместить их в отдельном модуле (отличном от того, где располагается функция main( )). Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника) и выдать на консоль вычис-ленные с помощью написанных функций значения его периметра и площади. */
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include "lab4.h"

int main(){
    int a,b,c,p;
    double s;
    printf("Введите размеры треугольника: ");
    scanf("%d %d %d", &a, &b, &c);
  if (check(a, b, c)){
    printf("Тругольник существует\n");
    p = perimetr(a, b, c);
    s = square(a, b, c);
    printf("Perimeter = %d\n", p);
    printf("Double square = %lf", s);
  }
    else 
    printf("Прямоугольника не существует");
  return 0;
}



в доп.файле:

#include <stdbool.h>
#include <stdio.h>
#include <math.h>
bool check(int a, int b, int c){
    if ((a+b>c) && (c+b>a) && (a+c>b)){
      return true;
    }
    else
    {
      return false;
    }
    
}

int perimetr(int a, int b, int c){
    return a + b + c;}

double square(double a, double b, double c){
    return (sqrt((a+b+c)/2 * ((a+b+c)/2 - a) * ((a+b+c)/2 - b) * ((a+b+c)/2 - c)));}
    
