#include<stdio.h>
#include<string.h>

#define MAXN 75

int pc[MAXN], cc[MAXN];
char ct[MAXN];
int Ad[MAXN], N, key;
int v[150];

char tx[] = "_abcdefghijklmnopqrstuvwxyz.";

void Ini() {
	int i, j;
	for(i = 0; tx[i]; i++) {
		j = tx[i];
		v[j] = i;
	}
}

void Set() {
	int i, j;
	for(j = 0; ct[j]; j++) {
		i = (j*key) % N;
		Ad[j] = i;
	}
}

void Gen() {
	int i,  k;
	for(i = 0; i<N; i++) {
		k = cc[i] + i;
		k = k % 28;
		pc[Ad[i]] = k;
	}
}

void Print() {
	int i;
	for(i = 0; i<N; i++)
		printf("%c",tx[pc[i]]);

}

void Cal(){
	int i, j;
	N = strlen(ct);
	for(i = 0; i<N; i++){
		j = ct[i];
		cc[i] = v[j];
	}
	Set();
	Gen();
	Print();
}

int main() {
	Ini();
	while(scanf("%d",&key) == 1) {
		if(!key) break;
		scanf("%s",ct);
		Cal();
		printf("\n");
	}
	return 0;

}
