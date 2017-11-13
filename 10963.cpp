#include<iostream>
#include<math.h>

using namespace std;

int main() {
  	int k, x, y, t = 0, w, c, d, z;
	cin>>k;
	while(k--) {
		cin>>w;
		z = w;
		c = 1;
		cin>>x>>y;
		d = abs(x-y);
		w--;
		while(w--) {
			cin>>x>>y;
			if(abs(x-y) == d)c++;
		}
		if(t++) cout<<endl;
		if(c == z) cout<<"yes\n";
		else cout<<"no\n";
	}
	return 0;

}
