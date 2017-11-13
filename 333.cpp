#include<stdio.h>
#include<string.h>
#include<ctype.h>

char Input[100];

int Iscorrect() {
	int i,  d = 0, x = 0, up, lo;
	int per = 0;
	int tsum = 0;
	for(lo = 0; Input[lo] == ' ' || Input[lo] == '\t' || isalpha(Input[lo]); lo++){
		if(Input[lo] == 'X') break;
	}
	for(up = strlen(Input)-1;Input[up] ==' '||Input[up]=='\t'||isalpha(Input[up]); up--){
		if(Input[up] == 'X') break;
	}
	for(i = lo; i<=up; i++) {
		if( Input[i] == '-') continue;
		else if(isdigit(Input[i])) {
			//if(d >= 10 || x) return 0;
			d++;
			per += Input[i] - '0';
			tsum += per;
		}
		else if(Input[i] == 'X') {
			if(d != 9) return 0;
			x = 1;
			per += 10;
			tsum += per;
			d++;
		}
		else return 0;
	}
	if(tsum % 11 == 0 && d >=10) return 1;
	return 0;
}



void Print() {
	int ind = 0, lo, up, k, l;
	char temp[85];
	l = strlen(Input);
	for(lo = 0; Input[lo] == ' ' || Input[lo] == '\t'; lo++);
		
	for(up = strlen(Input)-1;Input[up] ==' '||Input[up]=='\t'; up--);
		
	
	for(k = lo; k<=up; k++)
		temp[ind++] = Input[k];
	temp[ind] = NULL;
	printf("%s ",temp);
}

int main() {
	int i;

	while(gets(Input)) {
		for(i = 0; Input[i]; i++){
			if(Input[i] == '\n')
				Input[i] = NULL;
		}
		if(strlen(Input) == 0) {
			printf(" is incorrect.\n");
			continue;
		}
		Print();
		if(Iscorrect()) 
			printf("is correct.\n");
		else printf("is incorrect.\n");

	}
	return 0;
}
