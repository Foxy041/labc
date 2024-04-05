/*Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы 
массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сум-му, 
разность или произведение данных матриц (их передать по указателю) и возвра-щающую указатель на массив-результат. Разместить эту 
функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения по-лученного вектора.*/
#include <stdio.h>
#include <stdlib.h>

int n, i, j, c;
float sum();
float minus();
float impr();

int main() {
	char st;
	printf("size: ");
	scanf("%d", &n);
	double m[n][n], m1[n][n];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			scanf("%lf %lf", &m[i][j], &m1[i][j]);}}
	
	printf("\n operation: ");
	scanf("%c", &st);
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (st == '+'){
				c ++;
				if (c % n == 0 || c == n){
					printf("  %.1lf\n", sum([i][j]);}
				else {printf("  %.1lf", sum([i][j]);}}
				}}
	return 0;}

float *sum(){
	double s[n][n];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			s[i][j] = m[i][j] + m1[i][j];}}
	return s;}

float minus(){
	double mins[n][n];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			mins[n][n] = m[i][j] - m1[i][j];}}
	return mins;}

float impr(){
	double im[n][n];
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			im[n][n] = m[i][j] * m1[i][j];}}
	return im;}
