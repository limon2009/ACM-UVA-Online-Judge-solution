#include<iostream>
#include<math.h>

using namespace std;

typedef long long ss;

void Cal(ss n, ss Size) {
	ss mid, sq, d, x ,y, temp, p, line, colum;
	d = ceil(sqrt(n));
	if(d%2 == 0) d++;
	p = d*d;
	mid = Size/2 + 1;
	x = mid + ((d-3)/2 + 1);
	y = x;
	temp = p - d + 1;
	if(n >= temp && n <= p) {
		line = x - (p - n);
		colum = y;
		cout<<"Line = "<<line<<", column = "<<colum<<".\n";
		return;
	}
	sq = temp - d + 1;
	if(n >= sq && n <= temp) {
		colum = x - (temp - n);
		line = x - d + 1;
		cout<<"Line = "<<line<<", column = "<<colum<<".\n";
		return;
	}
	temp = sq - d + 1;
	x = x - d + 1;
	y = x;
	if(n >= temp && n <= sq) {
		line = x + (sq - n);
		colum = y;
		cout<<"Line = "<<line<<", column = "<<colum<<".\n";
		return;
	}
	x = x+d - 1;
	sq = temp - d + 2;
	if(n >= sq && n <= temp) {
		line = x;
		colum = y + (temp - n);
		cout<<"Line = "<<line<<", column = "<<colum<<".\n";
		return;
	}
}
int main() {
	ss sz, n;
	while(cin>>sz>>n) {
		if(!sz && !n) break;
		Cal(n,sz);
	}
	return 0;

}
