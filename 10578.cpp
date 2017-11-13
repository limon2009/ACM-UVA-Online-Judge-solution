#include<stdio.h>
#include<string.h>

int Fre[10];
char play[100];
char Fg[500000];

int Index() {
	int i, j = 1, sum = 0;
	for(i = 6; i>=1; i--) {
		sum += Fre[i]*j;
		j *= 10;
	}
	return sum;
}

int Recur(int sum, int n) {
	int i, k, f = 0, ind;
	if(sum > 31) return 1;
	if(sum == 31) return 0;
	Fre[n]++;
	//ind = Index();
	//if(Fg[ind]) return Fg[ind]-1;
	for(i = 1; i<=6; i++) {
		if(Fre[i] >= 4) continue;
		k = Recur(sum+i,i);
		if(!k) {
			f = 1;
			break;
		}
	}
	//ind = Index();
	Fre[n]--;
	//Fg[ind] = 1;
	//if(f) Fg[ind] = 2;
	if(f) return 1;
	return 0;
}

void Cal(){
	int i, sum = 0, l, k;
	for(i = 1; i<7; i++) Fre[i] = 0;
	for(i = 0; play[i]; i++){
		l = play[i] - '0';
		sum += l;
		Fre[l]++;
	}
	l = i;
	if(l == 0) {
		printf("%s A\n",play);
		return;
	}
	if(sum == 31) {
		printf("%s %c\n",play,((l-1)%2)+65);
		return;
	}
	for(i = 1; i<7; i++) {
		if(Fre[i] >= 4) continue;
		k = Recur(sum+i,i);
		if(!k) {
			printf("%s %c\n",play,(l%2)+65);
			return;
		}
	}
	printf("%s %c\n",play,(l+1)%2+65);
}

int main() {
//	freopen("c:\\h.txt","r",stdin);
	while(gets(play)) {
		Cal();
	}
	return 0;

}
