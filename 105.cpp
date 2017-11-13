#include<stdio.h>
#include<string.h>

#define  MAXN 10000

int H[MAXN+2];
int MAX;

void Print() {
   int i, p, x;
   for(i = 0; i<= MAX; i++)
	   if(H[i] != 0) break;
   printf("%d %d ",i, H[i]);
   p = i;
   x = H[i];
   while(1) {
       for(p = i; H[p]== x && p < MAX; p++);
       if(p >= MAX) {
    	   printf("%d 0\n",p);
		   break;
	   }
	   if(H[p] > x) printf("%d ",p);
	   else printf("%d ",p);
	   printf("%d ",H[p]);
	   i = p;
	   x = H[p];
   }
	   	  
}

int main() {
	   int x, h, y, f;
	   int i;
	   char input[100];
	   MAX = 0; 
	  // freopen("c:\\h.txt","r",stdin);
	   while(gets(input)) {
		   for(i = 0; input[i]; i++)
			   if(input[i] == '\n')
				   input[i] = NULL;
           if(strlen(input) <= 0) break;
           f = sscanf(input,"%d%d%d",&x,&h,&y);
           if(f <= 2) break;
		   for(i = x; i< y; i++){
			   if(H[i] < h)
	   			   H[i] = h;
		   }
		   if(y > MAX) 
			  MAX = y;
	   }
       Print();
       return 0;    
 
}
