/*Создать текстовый файл с записями следующего вида: 
Иванов Петр Сергеевич 1975 
Сидоров Николай Андреевич 1981 
…. 
Воробьянинов Ипполит Матвеевич 1978 
Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.  */


#include <stdio.h>

int main() 
{
    FILE *f1, *f2;
    
    f1 = fopen("input.txt", "r");
    f2 = fopen("output.txt", "w");
    
    char name[20]; 
    char last_name[20];
    char middle_name[20];
    int year;

    while (fscanf(f1, "%s %s %s %d", last_name, name, middle_name, &year) !=EOF) 
    {
        if (year > 1980) 
        {
            fprintf(f2, "%s %s %s %d\n", last_name, name, middle_name, year);
        }
    }

    fclose(f1);
    fclose(f2);

    return 0;
}
