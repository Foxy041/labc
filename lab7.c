/*Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов 
типа humen.
Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения.
Вывести результат.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct human {
    char name[256];
    char surname[256];
    int birth_year;
};

void sort_array(struct human arr[], int size) {
    int i, j;
    struct human temp;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j].birth_year > arr[j + 1].birth_year) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Rus");

    struct human humans1[4];
    struct human humans2[4];

    printf("данные для массива:\n");
    for (int i = 0; i < 4; i++) {
        printf("Введите имя фамилию год рождения человека №%d:\n", i + 1);
        scanf("%s %s %d", humans1[i].name, humans1[i].surname, &humans1[i].birth_year);
    }

    sort_array(humans1, 4);

    printf("\nмассив по году рождения:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s %s %d\n", humans1[i].name, humans1[i].surname, humans1[i].birth_year);
    }

    return 0;
}
