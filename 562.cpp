#include<iostream>
#include<string.h>

using namespace std;

#define MAXN 50002

int C[101], coin, sum;
char F[MAXN];

void Cal() {
	int half = sum/2, i, j;
	F[0] = 1;
	for(i = 0; i<coin; i++) {
		if(C[i] > half) continue;
		for(j = half - C[i]; j>=0; j--)
			if(F[j])
				F[j+C[i]] = 1;
		if(F[half]) break;
	}
	for(i = half; i>=0; i--)
		if(F[i]) break;
	j = (sum - i);
	j = j - i;
	cout<<j<<endl;
}

int main() {
	int n, i;
	cin>>n;
	while(n--) {
		sum = 0;
		cin>>coin;
		for(i = 0; i<coin; i++){
			cin>>C[i];
			sum += C[i];
		}
		Cal();
		if(n) {
			for(i = 1; i<= sum/2; i++)
				F[i] = 0;
		}
	}
	return 0;

}
