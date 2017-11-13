#include<stdio.h>
#include<string.h>

char str[30];
int N;

int Countspace() {
	int i, c = 0;
	for(i = 0; str[i]; i++) 
		if(str[i] != 'X') c++;
	return c;
}


void Cal() {
	int a[30] = {0};
	int i, j, min = 100;
	for(i = 0; i<N; i++) {
		gets(str);
		a[i] = Countspace();
		if(a[i] < min)
			min = a[i];
	}
	j = 0;
	for(i = 0; i<N; i++)
		j += a[i] - min;
	printf("%d\n",j);
}


int main() {
	char input[100];
	while(gets(input)) {
		sscanf(input,"%d",&N);
		if(!N) break;
		Cal();
	}
	return 0;

}

