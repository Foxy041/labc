/*Реализовать программу-калькулятор с возможностью выполнения арифметиче-ских действий (+, -), унарный и бинарный вариант. 
У пользователя запрашивается вы-ражение, например, "-123.5 + 4 - 456+56", программа должна решить выражение. Для разбора 
входной строки использовать функцию strok.*/

int main(){
	int i, j;
    char s[32], sign[2] = "+-", si[16];
    const char cu[4] = " +-";
	fgets(s, 32 , stdin);
    float res;
    char *c = strtok(s, cu);
	
	for(i = 0; i < 32; i++){ 
		for(j = 0; j < 2; j++){
			if(s[i] == sign[j]){
				si[i] = sign[j];}}}
	
    while(c != 0){
    	if(s[0] == '-'){
			res -= atof(c);
			printf("%.2f %s\n", res, c);
			c = strtok(0, cu);
			printf("%.2f %s\n", res, c);
	    	for(j = 1; j < 16; j++){
				switch(si[j]){
					case '+':
						printf("%.2f\n", res);
						res += atof(c);
						printf("%.2f %s\n", res, c);
						c = strtok(0, cu); break;
					case '-':
						res -= atof(c);
						//printf("%.2f ", res);
						c = strtok(0, cu); break;}}}
		else{
			for(j = 0; j < 16; j++){
				switch(si[j]){
					case '+':
						res += atof(c);
						//printf("%.2f ", res);
						c = strtok(0, cu); break;
					case '-':
						res -= atof(c);
						//printf("%.2f ", res);
						c = strtok(0, cu); break;}}}}
					
	printf("\nresult: %.2f ", res);
	return 0;}
