#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char table[6][6][3];
char ss[6][3];
int rank[300], A[6];

int com(const void *a, const void *b) {
	return *(int *)b - *(int *)a;
}

void Ini() {
	char tt[] = "A23456789XJQK";
	int i, j;
	for(i = 0; tt[i]; i++) {
		j = tt[i];
		rank[j] = i;
	}
}



int Fourofkind() {
	int i, k, j;
	int a[10] = {0};
	for(i = 0; i<5; i++) {
		if(a[i]) continue;
		k = 1;
		for(j = i+1; j<5; j++) {
			if(ss[i][0] == ss[j][0]){
				k++;
				a[j] = 1;
			}

		}
		if(k == 4) return 1;
	}
	return 0;
}

int Fullhouse() {

	int a[10] = {0};
	int b[10] = {0};
	int i, j, c ;
	for(i  = 0; i<5; i++) {
		if(a[i]) continue;
		c = 1;
		for(j = i+1; j<5; j++) {
			if(ss[i][0] == ss[j][0]) {
				c++;
				a[j] = 1;
			}
		}
		b[c] ++; 
	}
	if(b[3] == 1 && b[2] == 1) return 1;
	return 0;
}

int Flush() {
	int i;
	for(i = 1; i<5; i++) 
		if(ss[i][1] != ss[i-1][1]) return 0;
	return 1;
}

int Straight() {
	int i, j, d = 1, c, k;
	int f[15] = {0};
	for(i = 0; i<5; i++) {
		j = ss[i][0];
		c = rank[j];
		f[c] = 1;
		k = c;
	}
	c = k+1;
	c %= 13;
	while(f[c]) {
		d++;
		c++;
		c %= 13;
	}
	c = k-1 + 13;
	c %= 13;
	while(f[c]) {
		d++;
		c--;
		c = (c+13)%13;
	}
	if(d == 5) return 1;
	return 0;
}

int Threeofakind() {
	int a[6] = {0};
	int i, c ;
	for(i = 0; i<5; i++) {
		if(a[i]) continue;
		c = 1;
		for(int j = i+1; j<5; j++) {
			if(ss[i][0] == ss[j][0]){
				c++;
				a[j] = 1;
			}
		}
		if(c == 3) return 1;
	}

	return 0;
}

int Twopair() {

	int a[7] = {0};
	int b[7] = {0};
	int i, j, c ;
	for(i  = 0; i<5; i++) {
		if(a[i]) continue;
		c = 1;
		for(j = i+1; j<5; j++) {
			if(ss[i][0] == ss[j][0]) {
				c++;
				a[j] = 1;
			}
		}
		b[c] ++; 
	}
	if(b[2] == 2) return 1;
	return 0;
}

int Onepair() {
	int a[6] = {0};
	int i, c ;
	for(i = 0; i<5; i++) {
		if(a[i]) continue;
		c = 1;
		for(int j = i+1; j<5; j++) {
			if(ss[i][0] == ss[j][0]){
				c++;
				a[j] = 1;
			}
		}
		if(c == 2) return 1;
	}

	return 0;
}


int Decide() {
	int f, s;
	if(Fourofkind()) return 8;
	if(Fullhouse())  return 7;
	f = Flush();
	s = Straight();
	if(s && f) return 9;
	if(f) return 6;
	if(s) return 5;
	if(Threeofakind()) return 4;
	if(Twopair()) return 3;
	if(Onepair()) return 2;
	return 1;
}

void Cal() {
	int a[10] = {0};
	int i, j, d;
	for( i = 0; i<5; i++) {
		for(j = 0; j<5; j++)
			strcpy(ss[j],table[i][j]);
		d = Decide();
		a[d]++;
	}
	for(i = 0; i<5; i++) {
		for(j = 0; j<5; j++)
			strcpy(ss[j],table[j][i]);
		d = Decide();
		a[d]++;
	}
	printf("%d",a[1]);
	for(i = 2; i<=9; i++)
		printf(", %d",a[i]);
	printf("\n");
}

void ReadCase() {
	int i, j, k = 0;
	char input[100];
	while(gets(input)) {
		for(i = 0; input[i]; i++) 
			if(input[i] == '\n')
				input[i] = NULL;
		if(strlen(input) == 0 ) break;
		sscanf(input,"%s%s%s%s%s",table[k][0],table[k][1],
				table[k][2],table[k][3],table[k][4]);
		k++;
		if(k % 5 ==0)
			Cal();
	}
}
int main() {
	int kase;
	char in[100];
	///freopen("c:\\h.txt","r",stdin);
	gets(in);
	sscanf(in,"%d",&kase);
	gets(in);
	Ini();
	//scanf("%d",&kase);
	while(kase--) {
		ReadCase();
	//	Cal();
		if(kase) printf("\n");
	}
	return 0;

}
