#include<stdio.h>
#include<list>

using namespace std;

#define maxn 5000

list<int>link1[maxn+2];
char C[maxn+2];
int Mark[maxn+2], ind;
int Rec[maxn+2];

int N;
/*
void MakeLink(int u) {
	int v;
	list<int>::iterator p;
	C[u] = 1;
	for(p = link1[u].begin(); p != link1[u].end(); p++ ){
		v = *p;
		if(C[v]) continue;
		link2[v].push_back(u);
		MakeLink(v);
	}
}
*/
int MarkPath(int u, int des, int level) {
	int v, d;
	list<int>::iterator p;
	C[u] = 1;
	Rec[level] = u;
	Mark[ind++] = u;
	if(des == u){
		return level;
	}
	for(p = link1[u].begin(); p != link1[u].end(); p++ ){
		v = *p;
		if(C[v]) continue;
		d = MarkPath(v,des,level+1);
		if(d) return d;
		//return MarkPath(v, des, level+1);
	}
	return 0;
}

/*
int Find(int u, int level) {
	int v;
	if(C[u]) return level + Mark[u];
	list<int>::iterator p;
	for(p = link2[u].begin(); p != link2[u].end(); p++ ){
		v = *p;
		return Find(v, level+1);
	}	
	return 0;
}
*/
void Clear(int d) {
	int i, u;
	for( i = 0; i<ind; i++) {
		u = Mark[i];
		C[u] = 0;
	}
}

void Cal() {
	int n, u, v, d;
	//MakeLink(1);
	for(n = 1; n<= N; n++)
		C[n] = 0;
	scanf("%d",&n);
	while(n--) {
		ind = 0;
		scanf("%d%d",&u,&v);
	    d =	MarkPath(u,v,0);
		if(d % 2 == 0) printf("The fleas meet at %d.\n",Rec[d/2]);
		else{
			u = Rec[d/2];
			v = Rec[d/2+1];
			if( u > v) {
				d = u;
				u = v;
				v = d;
			}
			printf("The fleas jump forever between %d and %d.\n",u,v);
		}
		Clear(ind);
	}
}

void Free() {
	int i;
	for(i = 1; i<= N; i++) {
		link1[i].clear();
		//link2[i].clear();
	}
}

int main() {
	int i, u, v;
	//freopen("c:\\h.txt","r",stdin);
	while(scanf("%d",&N) && N) {
		for(i = 0; i+1<N; i++) {
			scanf("%d%d",&u,&v);
			link1[u].push_back(v);
			link1[v].push_back(u);
		}
		Cal();
		Free();
	}
	return 0;

}
