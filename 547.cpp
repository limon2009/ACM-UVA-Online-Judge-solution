#include<stdio.h>
#include<math.h>
#define MAXN 3002


char flag[MAXN];

struct sss {
	int parent;
	int len;
}ss[MAXN];

int Sum(int n) {
	int sum = 0;
	while(n) {
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int  Recur(int n) {
	int i, j, limit, sum = 0;
	if(flag[n]) return ss[n].len;
	flag[n] = 1;
	limit = (int)sqrt(n);
	for(i = 1; i<= limit; i++) {
		if(n % i == 0) {
			sum += Sum(i);
			if(i != n/i)
				sum += Sum(n/i);
		}
	}
	if(sum == n) {
		ss[n].parent = -1;
		ss[n].len = 1;
		return 1;
	}
	j = Recur(sum);
	ss[n].len = j+1;
	ss[n].parent = sum;
	return j+1;
}

void Print(int n) {
	while(n>0) {
		printf(" %d",n);
		n = ss[n].parent;
	}
	printf("\n");
}
void Cal(int n, int m) {
	int max = 0, st, i;
	for(i = n; i<= m; i++) {
		if(ss[i].len>max) {
			st = i;
			max = ss[i].len;
		}
	}
	Print(st);
}

int main() {
	int i, n, m, k = 1;
	ss[1].parent = -1;
	ss[1].len = 1;
	for(i = 2; i<=3000; i++) {
		if(!flag[i])
			Recur(i);
	}
	while(scanf("%d%d",&n,&m) == 2) {
		printf("Input%d: %d %d\n",k,n,m);
		printf("Output%d:",k++);
		if(n<m) Cal(n,m);
		else Cal(m,n);
	}
	return 0;

}
