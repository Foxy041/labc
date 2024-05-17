/*Создать в отдельном модуле функции с переменным количеством аргументов, которая вычисляет их сумму, максимум, минимум, среднее 
арифметическое.*/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


double sum(int n, ...){
	double res;
	va_list p;
	va_start(p, n);
	for(;n > 0; n--)
		res += va_arg(p, double);
	va_end(p);
	return res;}

double min(int n, ...){
	va_list p;
	va_start(p, n);
	double res = va_arg(p, double);
	for(;n-1 > 0; n--)
		if(res > va_arg(p, double)){
			res = va_arg(p, double);}
	va_end(p);
	return res;}


double max(int n, ...){
	va_list p;
	va_start(p, n);
	double res = va_arg(p, double);
	for(;n > 0; n--)
		if(res < va_arg(p, double)){
			res = va_arg(p, double);}
	va_end(p);
	return res;}
	

double mid(int n, ...){
	double res, nums = n;
	va_list p;
	va_start(p, n);
	for(;n > 0; n--)
		res += va_arg(p, double);
	va_end(p);
	return res/nums;}

int main(){
	int a = 1000, b = 300;
	printf("%.2f\n", sum(5, 14.3, 45.3, 35.5, 435.5, (double)a));
	printf("%.2f\n", min(5, 14.3, 45.3, 35.5, 435.5, (double)a));
	printf("%.2f\n", max(5, (double)a, 14.3, 45.3, 35.5, 435.5));
	printf("%.2f\n", mid(5, 14.3, 45.3, 35.5, 435.5, (double)a));
	return 0;}
