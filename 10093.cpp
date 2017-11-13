#include<stdio.h>
#include<string.h>

char ss[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char R[10000];

int VAL[300], MAX;
int SUM;
void SET() {
	int i, j;
	for(i = 0; ss[i]; i++) {
		j = ss[i];
		VAL[j] = i;
	}
}

void GET() {
    int i, j;
	SUM = MAX = 0;
    for(i = 0; R[i]; i++) {
		j = R[i];
		if(MAX<VAL[j]) MAX = VAL[j];
		SUM += VAL[j];
	}
}


void CAL() {
    int i;
	if(MAX <=1) { printf("2\n"); return; }
	for(i = MAX; i<=61; i++){
		if(SUM %i == 0) {
			printf("%d\n",i+1);
			return;
		}
	}
	printf("such number is impossible!\n"); 
}


int main() {
    SET();
	while(gets(R)) {
		GET();
		CAL();
	}
	return 0;

}
