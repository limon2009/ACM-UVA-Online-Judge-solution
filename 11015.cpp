#include<iostream>
#include<stdio.h>

using namespace std;

#define maxn 25
#define INF 21474836
#define MIN(a, b) (a>b?b:a)

char SS[maxn][15];

int Cost[maxn][maxn];
int N, M;

void Ini() {
	int i, j;
	for(i = 1; i<= N; i++) {
		for(j = 1; j<= N; j++)
			Cost[i][j] = INF;
		Cost[i][i] = 0;
	}
}

void Floyd() {
	int i, j, k;
	for(k = 1; k<= N; k++) {
		for(i = 1; i<= N; i++) {
			for(j = 1; j<= N; j++) {
				Cost[i][j] = MIN(Cost[i][j],Cost[i][k]+Cost[k][j]);
			}
		}
	}
}

void Cal() {
	int i, min = 10000000, c, res, j;
	Floyd();
	for(i = 1; i<= N; i++) {
		c = 0;
		for(j = 1; j<= N; j++) {
			c += Cost[j][i];
		}
		if(c < min) {
			min = c;
			res = i;
		}
	}
	cout<<SS[res]<<endl;
}

int main() {
	int i, u, v, c, ks = 1;
	char ss[520];
	//freopen("c:\\h.txt","r",stdin);
	while(gets(ss)) {
		sscanf(ss,"%d%d",&N,&M);
		if(!N && !M) break;
		Ini();
		for(i = 1; i<= N; i++)
			gets(SS[i]);
		for(i = 1; i<= M; i++) {
			gets(ss);
			sscanf(ss,"%d%d%d",&u,&v,&c);
			Cost[u][v] = c;
			Cost[v][u] = c;
		}
		cout<<"Case #"<<ks++<<" : ";
		Cal();
	}
	return 0;

}
