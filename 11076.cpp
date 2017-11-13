#include<iostream>

using namespace std;

typedef unsigned long long SS;

SS Fact[13];
int Fre[10];
SS N;

void Ini() {
	SS i, n = 1;
	Fact[0] = 1;
	for(i = 1; i<13; i++) 
		Fact[i] = Fact[i-1] * i;
}

SS Uniqe() {
	SS i;
	SS n = Fact[N-1];
	for(i = 0; i<10; i++) {
		if(!Fre[i]) continue;
		n /= Fact[Fre[i]];
	}
	return n;
}

SS One() {
	SS sum = 0, i;
	for(i = 1; i<10; i++) {
		if(!Fre[i]) continue;
		Fre[i] --;
		sum += Uniqe() * i;
		Fre[i]++;
	}
	return sum;
}

void Cal() {
	SS n, carry = 0, ind = 0;
	int i, a[13];
	n = One();
	if(!n) {
		cout<<n<<endl;
		return;
	}
	for(i = 0; i<N; i++) {
		a[ind++] = (carry + n) % 10;
		carry = (carry + n) / 10;
	}
	if(carry) cout<<carry;
	for(i = ind-1; i>=0; i--)
		cout<<a[i];
	cout<<endl;
}

int main() {
	SS i, n;
	Ini();
	while(cin>>N && N) {
		for(i = 0; i<N; i++) {
			cin>>n;
			Fre[n]++;
		}
		Cal();
		for(SS i = 0; i<10; i++) Fre[i] = 0;
	}
	return 0;

}
