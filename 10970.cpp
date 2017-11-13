#include<iostream>

using namespace std;

int main() {
	int n, m, k, d;
	while(cin>>n>>m) {
		k = n - 1 + n*(m-1);
		cout<<k<<endl;
	}
	return 0;

}
