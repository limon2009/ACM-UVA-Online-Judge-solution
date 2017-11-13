#include<iostream>
#include<math.h>

using namespace std;

#define maxn 1000
#define RP(n, m) for(i = n; i<= m; i++)
#define RR(m, n) for(j = m; j>=n; j--)
#define MAX(a,b) (a>b?a:b)

struct ss {
	int parent;
	int current;
	double val;
}D[maxn+2];

void Dynamic() {
	int i, j;
	double t;
	RP(1, 2){
		D[i].val = log10(i);
		D[i].current = i;
	}
	D[0].val = 0;
	D[1].parent = D[2].parent = -1;
	RP(3,maxn) {
		t = log10(i);
		RR(maxn,i) {
			if(D[j-i].val + t > D[j].val) {
				D[j].current = i;
				D[j].parent = j-i;
				D[j].val = D[j-i].val + t;
			}
		}
	}
}

void Print(int n) {
	if(D[n].parent <=0) {
		cout<<n;
		return;
	}
	Print(D[n].parent);
	cout<<" "<<D[n].current;
}

int main() {
	int n, ks, k = 0;
	Dynamic();
	cin>>ks;
	while(ks--) {
		cin>>n;
		if(k++) cout<<endl;
		Print(n);
		cout<<endl;
	}
	return 0;

}
