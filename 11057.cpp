#include<iostream>
#include<math.h>
#include<stdlib.h>

using namespace std;

int A[10002];
int N, S;

int com(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

void Cal() {
	int x, d, y, p = 0, q = N-1;
	int min = 10000000;
	qsort(A,N,sizeof(int),com);
	while(p < q) {
		if(A[p] + A[q] == S) {
			d = A[q] - A[p];
			if(d < min) {
				min = d;
				x = A[p];
				y = A[q];
			}
			q--;
		}
		else if( A[p] + A[q] > S) q--;
		else p++;
	}
	cout<<"Peter should buy books whose prices are ";
	cout<<x<<" and "<<y;
	cout<<".\n";
	
}
int main() {
	int i;
	while(cin>>N) {
		for(i = 0; i<N; i++) {
			cin>>A[i];
		}
		cin>>S;
		Cal();
		cout<<endl;
	}
	return 0;

}
