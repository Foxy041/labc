/*Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов 
типа humen.
Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения.
Вывести результат.*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct human {
    char name[256];
    char surname[256];
    int birth_year;
};

void sortbyyear(struct human arr[], int size) {
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
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    struct human *man1 = (struct human*)malloc(n * sizeof(struct human));

    FILE *file = fopen("input.txt", "r");

    for (int i = 0; i < n; i++) {
        fscanf(file, "%s %s %d", man1[i].name, man1[i].surname, &man1[i].birth_year);
        printf("%s %s %d\n", man1[i].name, man1[i].surname, man1[i].birth_year);
    }

    fclose(file);

    sortbyyear(man1, n);

    file = fopen("output.txt", "w");

    for (int i = 0; i < n; i++) {
        printf("%s %s %d\n", man1[i].name, man1[i].surname, man1[i].birth_year);
        fprintf(file, "%s %s %d\n", man1[i].name, man1[i].surname, man1[i].birth_year);
    }

    fclose(file);

    free(man1); 

    return 0;
}
