#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 35000
char a[MAX+2];
int P[5000];

struct node{
	int info;
	node *next;
};
node *list;


void NS(int n)  {
	node *p;
	if(n == -1) {
     node *x = list;
	 while(x->next != NULL)
		 x = x->next;
	 x->next = list;
	 return ;
	}  
	
	p = (node *)malloc(sizeof(node));
	p->next = list;
	p->info = n;
	list = p;
}


int prime_table(){
	int i,j,k=0;
	for(i = 2; i<= MAX; i ++) a[i] = 1;
	for(i = 2; i<= sqrt(MAX); ) {
		for(j = i + i; j<= MAX; j += i)
			a[j] = 0;
		for(i++; !a[i]; i++);
	}
	for(i = 2; i<= MAX; i ++)
		if(a[i])
			P[k++] = i;
	int x = k;
	return 0;
}


int LOAD(int N)  {
	int i;
	list = NULL;
	for(i = N; i >= 1; i --)
      NS(i);
	NS(-1);
	return 0;
}


void compute(int N) {
     int i = 0,j,q= 0,en;
	 node *x = list;
	 while(1)  {
		 if(q ==0)
			 en = P[i] - 1;
		 else
			 en = P[i];
		 for(j = 1; j<en; j ++)
               x = x->next;
		 node *p = x->next;
		 x->next = p->next;
		 free(p);
		 i++;
		 q++;
		 if(q == N-1){ printf("%d\n",x->info); return;}
	 }
}



int main()  {
	 
	int N;
    
	prime_table();
	while(scanf("%d",&N) && N) {
		
		if(N == 1 || N == 2){
			printf("1\n");
			continue;
		}
		LOAD(N);
        compute(N);
        		
	}
	return 0;

}
