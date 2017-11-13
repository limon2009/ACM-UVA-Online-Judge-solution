#include<stdio.h>
#include<string.h>
#include<ctype.h>

char ss[8][5] = {"ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ" };
char xyz[100];
int X[30];

void Ini() {
	int i, j, k;
	for(i = 0; i<8; i++) {
		for( j = 0; ss[i][j]; j++) {
			k = ss[i][j] - 'A' + 1;
			X[k] = i + 2;
		}
	}
}

int main() {
	Ini();
	int k;
	while(gets(xyz)) {
		for(int i = 0; xyz[i]; i++) {
			if(xyz[i] == '-') printf("-");
			else if(isdigit(xyz[i])) printf("%c",xyz[i]);
			else {
				k = xyz[i] - 'A' + 1;
				printf("%d",X[k]);
			}
		}
		printf("\n");
	}
	return 0;
}
