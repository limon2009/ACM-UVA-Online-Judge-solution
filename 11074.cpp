#include<iostream>

using namespace std;

int S,T,N;

void Print(int n, char ch) {
	int i;
	for(i = 0; i<n; i++)
		cout<<ch;
}

void F() {
	int i, j, k, n;
	n = (S+T)*N + T;
	for(i = 0; i<N; i++) {
		for(j = 0; j<T; j++) {
			Print(n,'*');
			cout<<endl;
		}
		for(j = 0; j<S; j++) {
			for(k = 0; k<N; k++) {
				Print(T,'*');
				Print(S,'.');
			}
			Print(T,'*');
			cout<<endl;
		}
	}
	for(i = 0; i<T; i++){
		Print(n, '*');
		cout<<endl;
	}
}

int main() {
	int k = 1;
	while(cin>>S>>T>>N) {
		if(!S && !T && !N) break;
		cout<<"Case "<<k++<<":\n";
		F();
		cout<<endl;
	}
	return 0;

}
