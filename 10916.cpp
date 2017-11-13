#include<iostream>
#include<math.h>

using namespace std;

int main() {
	int y, i;
	double w, f;
	while(cin>>y && y) {
		w = log(4);
		for(i = 1960; i <= y; i += 10) 
			w *= 2;
		f = 0;
		i = 1;
		while(f < w ){
			f += log((double) ++i);
		}
		cout<<i-1<<endl;
	}
	return 0;

}
