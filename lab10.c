/*Написать программу вычисления максимального числа из введенных пользова-телем в виде одной строки. 
Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(x, y) ({\
 double r = 0, res = 0; \
 for(int j = 0; j < y-1; j++){ \
  if(x[j] < x[j+1]){ \
   r = x[j+1];}} \
 res = r; \
 printf("\nresult: %.2lf", res);})


int main(){
	int n, i;
	double nums[16], res;
	char s[64];
	const char cu[2] = " ";
	fgets(s, 64 , stdin);
	char *c = strtok(s, cu);
	
while(c != 0){
  for(i=0; i<16; i++){
   nums[i] = atof(c);
   c = strtok(0, cu);}}
 for(i=0; ;i++){
        if(nums[i] == '\0'){
   break;}
        n++;}

	for(i=0; ;i++){
        if(nums[i] == '\0'){
			break;}
        n++;}
		//res = max(atof(c), atof(strtok(0, cu)));)}
		
	max(nums, n);
	return 0;}
