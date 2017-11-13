#include<iostream>

using namespace std;

#define maxn 100

typedef long long  SS;

struct ss {
	SS male;
	SS female;
};

ss A[maxn*5];

void Gen() {
	SS male = 1, female = 0;
	A[1].female = 0;
	A[1].male = 1;
	A[0].female = 0;
	A[0].male = 0;
	for(int i = 2; i<200; i++) {
		A[i].male = A[i-1].male + A[i-1].female + 1;
		A[i].female = A[i-1].male;
	}
}

int main() {
	SS n;
	Gen();
	while(cin>>n && n >= 0) {
		cout<<A[n].male<<" "<<A[n].male+A[n].female + 1<<endl;
	}
	return 0;

}
