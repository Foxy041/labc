/*Создать текстовый файл с записями следующего вида: 
Иванов Петр Сергеевич 1975 
Сидоров Николай Андреевич 1981 
…. 
Воробьянинов Ипполит Матвеевич 1978 
Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.  */

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j, size = 5;
	
	int array[5] = {24, 54, 2, 5, 1};
	
	for (i = 0; i < size - 1; i++){
/* устанавливаем начальное значение минимального индекса */
    	int min_i = i;
/* находим индекс минимального элемента */
		for(j = i + 1; j < size; j++) {
			if(array[j] < array[min_i]) 
				min_i = j;}
/* меняем значения местами */
			int temp = array[i];
			array[i] = array[min_i];
			array[min_i] = temp;}
	
	for(i = 0; i < 5; i++){
		printf("%d ", array[i]);}
	return 0;}



	#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main(){
	int i;
	double r;
    char s[64], nums[2], *f1 = "t.txt", *f2 = "t1.txt"; ;
    setlocale(LC_ALL, "Rus");
    FILE *fr = fopen(f1, "r"), *fw = fopen(f2, "w");
    
	while(fgets(s, 64, fr) != NULL){
		for(i = 0; i < 65; i++){
			if(s[i] == '1' && s[i+1] == '9'){
				nums[0] = s[i+2];
				nums[1] = s[i+3];
				r = atof(nums);
				if(r < 80){
					fputs(s, fw);
					printf("%s", s);}}}}

    fclose(fr);
    fclose(fw);
    return 0;
}



 z [p rfr 'nj ltkfnm djj,ot ,kznm
