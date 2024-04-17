/*Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения. Объявить два массива из четырёх элементов типа humen.
Ввести с консоли или из файла элементы одного массива и построить на их основе другой, упорядочив элементы по годам рождения. Вывести
результат.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int sort(){
	int i, j, q, ar[5] = {1, 3, 4, 6, 8};
	

	for (i = 0; i < 5; i++){
		for (j = 0; j < 5 - i; j++){
			if(ar[j] > ar[j+1]){
				q = ar[j];
				ar[j] = ar[j+1];
				ar[j+1] = q;}}}
				
	for(i = 0; i < 5; i++){
		printf("%d", ar[i]);
	}
	
	return 0;
}




В ФАЙЛЕ
struct humen{
		char name[8], surname[16];
		int age;};

int main(){
	struct humen h1 = {"Alex", "Maslovic", 13};
	struct humen h;
	int i;
    setlocale(LC_ALL, "Rus");
    char s[64], nums[4], buf[16], *f1 = "t.txt", *f2 = "t1.txt";
    FILE *fr = fopen(f1, "r"), *fw = fopen(f2, "w");
    
	while (fgets(s, 64, fr) != NULL){
		for (i = 0; i < 64; i++){
			if (i < 8){
				strcpy(h.name[i], s[i]);}
			if (i > 8 && i < 32){
				strcpy(h.surname[i], s[i]);}
			if (s[i] == '1' && s[i+1] == '9'){
				nums[0] = s[i];
				nums[1] = s[i+1];
				nums[2] = s[i+2];
				nums[3] = s[i+3];
				h.age = atoi(nums);}}
		printf("%s %s %d", h.name, h.surname, h.age);}
	
	printf("%s %s %d", h1.name, h1.surname, h1.age);
    fclose(fr);
    fclose(fw);
	return 0;}
не ну тут нужен хелп бесспорно 
