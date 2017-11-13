#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXN 10003
char Str[1000000];

struct ss {
	int inor, por;
	int ind_in, ind_p;
	int Fg;
}Node[MAXN];

int node, Min, Ans;

void GetIn() {
	char *p;
	int n;
	p = strtok(Str," ");
	while(p) {
		n = atoi(p);
		Node[node].inor = n;
		Node[n].ind_in = node;
		node++;
		p = strtok(NULL, " ");
	}
}

void GetP() {
	char *p;
	int n;
	p = strtok(Str," ");
	while(p) {
		n = atoi(p);
		Node[node].por = n;
		Node[n].ind_p = node;
		Node[n].Fg = 0;
		node++;
		p = strtok(NULL, " ");
	}
}

void Recur(int u, int sum, int indu, int inds) {
	int k = 1, ip, d, n, newind;
	Node[indu].Fg = 1;
	if(indu > 1 && !Node[indu-1].Fg) {
		k = 0;
		d = inds - indu;
		ip = Node[u].ind_p;
		n = Node[ip-d].por;
		newind = Node[n].ind_in;
		Recur(n,sum+n,newind,indu);
	}
	if(indu<(node-1) && !Node[indu+1].Fg) {
		k = 0;
		ip = Node[u].ind_p;
		n = Node[ip-1].por;
		newind = Node[n].ind_in;
		Recur(n,n+sum,newind,inds);
	}
	if(k) {
		if(sum <= Min) {
			if(sum < Min){ Ans = u; Min = sum; }
			else if(Ans > u) Ans = u;
		}
	}
}
void Cal() {
	int n, m;
	if(node == 2) {
		printf("%d\n",Node[1].inor);
		return;
	}
	Min = 10000000;
	Ans = 10000000;
	n = Node[node-1].por;
	m = Node[n].ind_in;
	Recur(n,n,m,node);
	printf("%d\n",Ans);
	for(n = 1; n<node; n++)
		Node[n].Fg = 0;
}
int main() {
//	freopen("c:\\h.txt","r",stdin);
	while(gets(Str)) {
		node = 1;
		GetIn();
		gets(Str);
		node = 1;
		GetP();
		Cal();
	}
	return 0;

}
