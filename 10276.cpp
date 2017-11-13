#include<stdio.h>
#include<math.h>

int N, MAX;
struct ss {
   int pre;
} Peg[51];

void SolveCase() {
    int i, j, k, f, v, m;
	MAX = 0;
	for(i = 1; ; i++) {
		f = 1;
		for(j = 0; j<N; j++) {
			k = Peg[j].pre;
			if(k >MAX) MAX = k;
			if(k == 0) { 
				Peg[j].pre=i;
				f = 0;
				break;
			}
			v = Peg[j].pre + i;
			m = sqrt(v);
			if(m*m == v) {
			   Peg[j].pre = i;
			   f = 0;
			   break;
			}
		}
		if(f) break;
	}
	printf("%d\n",i-1);
}

void Free() {
   int i, j;
   for(i = 0; i<N; i++)
	      Peg[i].pre = 0;
}

int main() {
    int kase;
	scanf("%d",&kase);
	while(kase--) {
	   scanf("%d",&N);
	   SolveCase();
	   Free();
	}
	return 0;

}
