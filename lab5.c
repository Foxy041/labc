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









#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "mylib.h"

int main() {
    int n;
    printf("Введите размерность матрицы: ");
    scanf("%d", &n);

    double* massive_1 = (double*)malloc(n * n * sizeof(double)); 
    double* massive_2 = (double*)malloc(n * n * sizeof(double));

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            printf("massive_1[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &massive_1[i * n + j]);
        }
    }

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            printf("%lf ", massive_1[i * n + j]);
        }
        printf("\n");
    }

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            printf("massive_2[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &massive_2[i * n + j]);
        }
    }

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            printf("%lf ", massive_2[i * n + j]);
        }
        printf("\n");
    }

    char math;
    printf("Введите операцию +, -, *: ");
    scanf(" %c", &math); //%c интерпретирует его числовое значение как символьное значение для отображения. 

    double* massives = f(massive_1, massive_2, n, math);

    for(int i = 0; i < n; i++) 
    {

        for(int j = 0; j < n; j++) 
        {
            printf("%lf ", massives[i * n + j]);
        }
        printf("\n");
    }

    free(massive_1);
    free(massive_2);
    free(massives);

    return 0;
}



mylib.h
double* f(double* massive_1, double* massive_2, int n, char math);

mylib.c
#include "mylib.h"
#include <malloc.h>

double* f(double* massive_1, double* massive_2, int n, char math) 
{
    double* massives = (double*)malloc(n * n * sizeof(double));

    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(math == '+') 
            {
                massives[i * n + j] = massive_1[i * n + j] + massive_2[i * n + j];
            } 
            else if(math == '-') 
            {
                massives[i * n + j] = massive_1[i * n + j] - massive_2[i * n + j];
            } 
            else if(math == '*') 
            {
                massives[i * n + j] = massive_1[i * n + j] * massive_2[i * n + j];
            }
        }
    }

    return massives;
}





#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main() {
    int n;
    printf("Введите размерность матрицы: ");
    scanf("%d", &n);

    double massive_1 = (double)malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++) {
        massive_1[i] = (double*)malloc(n * sizeof(double));
    }

    double massive_2 = (double)malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++) {
        massive_2[i] = (double*)malloc(n * sizeof(double));
    }

    inputmatrix(massive_1, n, '1');
    printmatrix(massive_1, n);

    inputmatrix(massive_2, n, '2');
    printmatrix(massive_2, n);
    
    char math;
    printf("Введите операцию +, -, *: ");
    scanf(" %c", &math);

    double** result = endresult(massive_1, massive_2, n, math);
    printmatrix(result, n);
    
    for(int i = 0; i < n; i++) {
        free(massive_1[i]);
        free(massive_2[i]);
        free(result[i]);
    }
    free(massive_1);
    free(massive_2);
    free(result);

    return 0;
}


mylib.h
void inputmatrix(double** matrix, int n, char num);
void printmatrix(double** matrix, int n);
double endresult(double massive_1, double** massive_2, int n, char math);

mylib.c
#include "mylib.h"

void inputmatrix(double** matrix, int n, char num) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("massive_%c[%d][%d] = ", num, i + 1, j + 1);
            scanf("%lf", &matrix[i][j]);
        }
    }
}

void printmatrix(double** matrix, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

double endresult(double massive_1, double** massive_2, int n, char math) {
    double result = (double)malloc(n * sizeof(double*));
    for(int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(math == '+') {
                result[i][j] = massive_1[i][j] + massive_2[i][j];
            } else if(math == '-') {
                result[i][j] = massive_1[i][j] - massive_2[i][j];
            } else if(math == '*') {
                result[i][j] = massive_1[i][j] * massive_2[i][j];
            }
        }
    }

    return result;
}
