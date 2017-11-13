#include<stdio.h>
#define MAXN 32002

char seiv[MAXN];
int Prime[4000];
int K, st, L, U;

struct ss {
	int inv;
	int fre;
	int st, en;
	int A[100];
}set[200];

void Prime_table() {
	int i, j;
	K = 1;
	for(i = 2; i*i<MAXN;) {
		for(j = i+i; j<MAXN; j+= i)
			seiv[j] = 1;
		for(i++; seiv[i]; i++);
	}
	Prime[0] = 2;
	for(i = 3; i<MAXN; i+= 2)
		if(seiv[i] == 0)
			Prime[K++] = i;
}

void Determinate() {
	int i, j, dif;
	st  = 0;
	for(i = 0; i<K-2; ){
		dif = Prime[i+1] - Prime[i];
		if(Prime[i+1]+ dif == Prime[i+2]) {
			set[st].st = Prime[i];
			set[st].inv = dif;
			set[st].fre = 0;
			j = 1;
			set[st].A[0] = Prime[i];
			while( Prime[i+1] - Prime[i]  == dif) {
				set[st].A[j++] = Prime[i+1];
				i++;
			}
			set[st].fre = j;
			set[st].en = Prime[i];
			st++;
		}
		else i++;
	}
	
}

void Print() {
	int i, j, p, q;
	for(i = 0; i<st; i++) {
		if(set[i].st>= L && set[i].en<= U){
			printf("%d",set[i].A[0]);
			for(j = 1; j<set[i].fre; j++) printf(" %d",set[i].A[j]);
			printf("\n");
		}
	}
}

int main() {
	Prime_table();	
	Determinate();
	int temp;
	while(1) {
		scanf("%d%d",&L,&U);
		if(!L && !U) break;
		if(L>U) {
			temp = L;
			L = U;
			U = temp;
		}
		Print();
	}
	return 0;

}

