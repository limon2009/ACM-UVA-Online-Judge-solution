#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ram[1001], r[11];
int Ind;

char Input[100];

int Empty() {
	int i;
	for(i = 0; Input[i]; i++) {
		if(Input[i] == '\n'){
			Input[i] = NULL;
			break;
		}
	}
	return strlen(Input) == 0;
}

void ReadCase() {
	Ind = 0;
	while(gets(Input)) {
		if(Empty()) break;
		ram[Ind++] = atoi(Input);
	}
}

void Cal() {
  int i ,ip = 0, a, b, c;
  for (i=1;;i++){
      a = ram[ip]/100;
      b = ram[ip]/10%10;
      c = ram[ip]%10;
      ip++;
      if (a == 1) break;
      if (a == 2) r[b] = c;
      else if (a == 3) r[b] = (r[b]+c)%1000;
      else if (a == 4) r[b] = (r[b]*c)%1000;
      else if (a == 5) r[b] = r[c];
      else if (a == 6) r[b] = (r[b]+r[c])%1000;
      else if (a == 7) r[b] = (r[b]*r[c])%1000;
      else if (a == 8) r[b] = ram[r[c]];
      else if (a == 9) ram[r[c]] = r[b];
      else if (a == 0 && r[c] !=0) ip = r[b];
   }
   printf("%d\n",i);
}

void Free() {
	int i;
	for( i = 0; i <= 1000; i++)
		ram[i] = 0;
	for(i = 0; i <= 9; i++)
		r[i] = 0;
}

int main() {
	int ks;
	//freopen("c:\\h.txt","r",stdin);
	gets(Input);
	ks = atoi(Input);
	gets(Input);
	while(ks--) {
		ReadCase();
		Cal();
		if(ks) printf("\n");
		Free();
	}
	return 0;

}
