#include<stdio.h>


int F[125];
char sv[2005];
char str[2005];

void Prime_table() {
	int i, j;
	sv[0] = sv[1] = 1;
	for(i = 2; i*i<=2000; ) {
		for(j = i+i; j<2000; j+= i)
			sv[j] = 1;
		for(++i; sv[i]; i++);
	}
}


void Cal() {
	int i, j, f = 1;
	for(i = 0; str[i]; i++) {
		j = str[i];
		F[j] ++;
	}
	for(i = 48; i<123; i++) {
		if(sv[F[i]] == 0) {
			printf("%c",i);
			f = 0;
		}
	}
	for(i = 48; i<123; i++) 
		F[i] = 0;
	if(f) printf("empty");
}

int main() {
	int ks, k = 1;
	Prime_table();
	scanf("%d",&ks);
	while(ks--) {
		scanf("%s",str);
		printf("Case %d: ",k++);
		Cal();
		printf("\n");
	}
	return 0;

}
