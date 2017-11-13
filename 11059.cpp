#include<iostream>

using namespace std;

#define MAX(a, b) (a > b ? a:b)
#define MIN(a, b) (a > b ? b:a)

typedef long long SS;

SS max, min, N;

void Cal(SS k) {
	SS i, n, mx, mn, MX = 0;
	cin>>n;
	max = min = n;
	MX = MAX(n, 0);
	for(i = 1; i<N; i++) {
		cin>>n;
		mx = max*n;
		mn = min*n;
		max = MAX(n,mx);
		max = MAX(max,mn);
		min = MIN(mn,n);
		min = MIN(min,mx);
		MX = MAX(max, MX);
	}
	cout<<"Case #"<<k<<": The maximum product is "<<MX<<".\n";
}
int main() {
	SS k = 1;
	while(cin>>N) {
		Cal(k++);
		cout<<endl;
	}
	return 0;

}
