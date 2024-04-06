/*Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double (значения n и элементы 
массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'. Написать функцию, вычисляющую сум-му, 
разность или произведение данных матриц (их передать по указателю) и возвра-щающую указатель на массив-результат. Разместить эту 
функцию в отдельном модуле (отличном от того, где располагается функция main()). Выдать на консоль значения по-лученного вектора.*/

ОДНОМЕРНЫЙ МАССИВ 

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "mylib.h"

int main() {
    int n;
    printf("vvedite razmer ");
    scanf("%d", &n);

    double* massive_1 = (double*)malloc(n * n * sizeof(double)); 
    double* massive_2 = (double*)malloc(n * n * sizeof(double));

    for(int i = 0; i<n; i++) 
    {
        for(int j = 0; j<n; j++) 
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

    for(int i = 0; i<n; i++) 
    {
        for(int j = 0; j<n; j++) 
        {
            printf("massive_2[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &massive_2[i * n + j]);
        }
    }

    for(int i = 0; i<n; i++) 
    {
        for(int j = 0; j<n; j++) 
        {
            printf("%lf ", massive_2[i * n + j]);
        }
        printf("\n");
    }

    char math;
    printf("vvedite operaziy ");
    scanf(" %c", &math); 

    double* massives = f(massive_1, massive_2, n, math);

    for(int i = 0; i<n; i++) 
    {

        for(int j = 0; j<n; j++) 
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

ФАЙЛ 
double* f(double* massive_1, double* massive_2, int n, char math);



ДВУМЕРНЫЙ МАССИВ
#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

int main() {
    int n;
    printf("vvedite razmer ");
    scanf("%d", &n);

    double** massive_1 = (double**)malloc(n * sizeof(double*));
    double** massive_2 = (double**)malloc(n * sizeof(double*));
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        massive_1[i] = (double*)malloc(n * sizeof(double));
        massive_2[i] = (double*)malloc(n * sizeof(double));
        result[i] = (double*)malloc(n * sizeof(double));
    }

   
    printf("vvedite matricy 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("massive_1[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &massive_1[i][j]);
        }
    }

   
    printf("matrica 1:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", massive_1[i][j]);
        }
        printf("\n");
    }
   
    printf("vvedite matricy 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("massive_2[%d][%d] = ", i + 1, j + 1);
            scanf("%lf", &massive_2[i][j]);
        }
    }

    printf("matrica 2:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", massive_2[i][j]);
        }
        printf("\n");
    }

    char math;
    printf("vvedite operaciy ");
    scanf(" %c", &math);

    result = f(massive_1, massive_2, n, math);

    
    printf("res:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", result[i][j]);
        }
        printf("\n");
    }

 
    for (int i = 0; i < n; i++) {
        free(massive_1[i]);
        free(massive_2[i]);
        free(result[i]);
    }
    free(massive_1);
    free(massive_2);
    free(result);

    return 0;
}

ФАЙЛ
double** f(double** massive_1, double** massive_2, int n, char math) {
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            switch (math) {
            case '+':
                result[i][j] = massive_1[i][j] + massive_2[i][j];
                break;
                
            
            case '-':
                result[i][j] = massive_1[i][j] - massive_2[i][j];
                break;
                
                
            case '*':
            
                for (int i = 0; i < n; i++)
      {
         for (int j = 0; j < n; j++)
         {
            result[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
               result[i][j] += massive_1[i][k] * massive_2[k][j];
            }
         }
      }
               
                break;
            default:
                printf("oshibka\n");
                for (int i = 0; i < n; i++) {
                    free(result[i]);
                }
                free(result);
                return NULL;
            }
        }
    }

    return result;
}
