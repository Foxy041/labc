/*Создать текстовый файл с записями, включающие имя/фамилию человека, год рождения, пол и рост (в метрах). Упорядочить элементы 
по году рождения, име-ни/фамилии, полу или росту. Вывести результат. Указать элемент, по которому следует упорядочить, через
консоль. А также реализовать возможность задавать несколько по-лей для упорядочивания.*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct person{
	char name[8], surname[16], sex[4];
	int age;
	float heigt;};

void sortn(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (strcmp(hw.name, hr[j].name) < 0); j--){ /*Функция strcmp начинает сравнивать по одному символу и как только будут найдены первые неодинаковые символы, функция проанализирует числовые коды этих символов*/
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}
		
void sortp(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (strcmp(hw.sex, hr[j].sex) > 0); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}
				
void sortd(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (hw.age < hr[j].age); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}

void sorth(struct person hr[], int n){
	int i, j;
	struct person hw;
	for(i = 1; i < n; i++){
		hw = hr[i];
		for(j = i - 1; (j >= 0) && (hw.heigt < hr[j].heigt); j--){
			hr[j+1] = hr[j];}
		hr[j+1] = hw;}}
		
int main(){
	setlocale(LC_ALL, "Rus");
	char n[8], sn[16], p[4], s[64], s1[64], *f = "text.txt", *f1 = "text1.txt";
	FILE *fr = fopen(f, "r"), *fr1 = fopen(f1, "r");
	int size = 0, j, i, q, m, k;
	while(fgets(s1, sizeof(s1), fr1)){
        size++;}
	fclose(fr1);
	printf("%d\n", size);
	float h;
	struct person hr[size];
	struct person hw[size];

	for(i = 0; i < size; i++){
		if(fgets(s, 64, fr) != NULL){
			sscanf(s,"%s %*s %*d %*s %*f",n), sscanf(s,"%*s %s %*d %*s %*f",sn),  /*Функция sscanf() идентична функции scanf(), но данные читаются из массива, адресуемого параметром buf, а не из стандартного потока ввода stdin.*/
			sscanf(s,"%*s %*s %d %*s %*f",&m), sscanf(s,"%*s %*s %*d %s %*f",p), \
			sscanf(s,"%*s %*s %*d %*s %f",&h);
			strcpy(hr[i].name, n), strcpy(hr[i].surname, sn), strcpy(hr[i].sex, p); /*Функция strcpy копирует данные из строки, на которую указывает аргумент source, в строку, на которую указывает аргумент destination, пока не встретится символ конца строки (нулевой символ)*/
			strcpy(hw[i].name, n), strcpy(hw[i].surname, sn), strcpy(hw[i].sex, p);			
			hr[i].age = hw[i].age = m;
			hr[i].heigt = hw[i].heigt = h;
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].sex, hr[i].heigt);}}
	
	printf("\n-\n");
	
	printf("name(1)/surname(2)/age(3)/sex(4)/height(5):");
	scanf("%d", &k);
	
	/*sort(hr, k, size);
	for(i = 0; i < size; i++){
		printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].sex, hr[i].heigt);}*/
	
	if(k == 1){
		sortn(hr, size);
		for(i = 0; i < size; i++){
			printf("%s %s %d %s %.2f\n", hr[i].name, hr[i].surname, hr[i].age, hr[i].sex, hr[i].heigt);}}
	
	fclose(fr);
	return 0;}

