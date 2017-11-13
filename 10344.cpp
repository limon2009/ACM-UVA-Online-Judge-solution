#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int A[10];
int B[10];



char Fg[10];


struct ss {
	int C[30];
	int ind;
};

ss V[6];

void Setting() {
	int i, j;
	for(i = 1; i<5; i++)
		V[i].ind = 0;
	V[5].C[0] = 23;
	V[5].ind = 1;

	for(i = 4; i>= 2; i --) {
		for(j = 0; j<V[i+1].ind; j++) {
			V[i].C[V[i].ind++] = (V[i+1].C[j] + A[i+1]);
			V[i].C[V[i].ind++] = (V[i+1].C[j] - A[i+1]);
			if(V[i+1].C[j] % A[i+1] == 0)
				V[i].C[V[i].ind++] = (V[i+1].C[j] / A[i+1]);
		}
	}
}


int Recur(int n, int level , int sum) {
	int i, j, d, f = 1;
	switch(n) {
	case 1:d = sum + A[level+1]; break;
	case 2:d = sum - A[level+1]; break;
	case 3:d = sum * A[level+1]; break;
	}
	for(j = 0; j<V[level+1].ind; j++) {
		if(V[level+1].C[j] == d) {
			f = 0;
			break;
		}
	}
	if(f) return 0;
	if(level == 4) return 1;
	for(i = 1; i<4; i++){
		if(Recur(i,level+1,d)) return 1;
	}

	return 0;
}


int Per(int n, int level) {
	int i, j, k;
	A[level] = B[n];
	if(level == 5) {
		Setting();
		for(j = 1; j<4; j++) {
			Setting();
			if(Recur(j,1,A[1])) return 1;
		}
		return 0;
	}

	Fg[n] = 1;

	for(i = 1; i<=5; i++) {
		if(Fg[i] == 1) continue;
		
		/*for( k = 1; k<i; k++)
			if(Fg[k] == 0) break;
		
		if(B[i] == B[k]) continue;*/

		j = Per(i,level+1);
		if(j) {
			Fg[n] = 0;
			return 1;
		}
		
	}
	Fg[n] = 0;
	return 0;
}


int com(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void Cal() {
	int i;
	qsort(B,6,sizeof(int),com);
	for(i = 1; i<= 5; i++) {
		if(B[i] == B[i-1]) continue;
		if(Per(i,1)) {
			printf("Possible\n");
			return;
		}
	}
	printf("Impossible\n");
}


int main() {
	int i, f, s;
	while(1) {
		f = 1;
		s = 1;
		for(i = 1; i<= 5; i++) {
			scanf("%d",&B[i]);
			if(B[i]) f = 0;
			s *= B[i];
		}
		if(f) break;
		if(s < 23) {
			printf("Impossible\n");
			continue;
		}
		Cal();
	}
	return 0;

}
