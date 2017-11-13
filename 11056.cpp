#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<ctype.h>

using namespace std;

int N;
struct ss {
	char nam[21];
	char nn[21];
	int time;
};

ss R[101];

int com(const void *a, const void *b) {
	ss *x, *y;
	x = (ss *)a;
	y = (ss *)b;
	if(x->time != y->time)
		return x->time - y->time;
	return strcmp(x->nn,y->nn);
}

void Cal() {
	int i, row = 1;
	qsort(R,N,sizeof(ss),com);
	for(i = 0; i<N; i++) {
		if(i % 2 == 0)
			cout<<"Row "<<row++<<endl;
		cout<<R[i].nam<<endl;
	}
}
int main() {
	int i, mn, sc, m, d, j;
	char min[10], sec[10],ms[10], cl[10];
	while(cin>>N) {
		for(i = 0; i<N; i++) {
			cin>>R[i].nam>>cl>>mn>>min>>sc>>sec>>m>>ms;
			d = mn*60 + sc;
			d = d*1000 + m;
			R[i].time = d;
			for(j = 0; R[i].nam[j]; j++)
				R[i].nn[j] = tolower(R[i].nam[j]);
			R[i].nn[j] = NULL;
		}
		Cal();
		cout<<endl;
	}
	return 0;

}
