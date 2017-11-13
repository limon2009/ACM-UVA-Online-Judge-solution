#include <stdio.h> 
#include <math.h> 

double d[101][101]; 
int x[101], y[101], t, h, n; 

void ReadData() { 
   int i; 
   scanf("%d", &n); 
   for (i = 1; i <= n; i++) 
      scanf("%d %d", &x[i], &y[i]); 
} 

void MakeSolu() { 
   int k, i, j; 
   double dis; 
   for (i = 1; i <= n - 1; i++){ 
      for (j = i + 1; j <= n; j++) { 
          dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);          
	      if (dis <= 100) { 
             d[i][j] = d[j][i] = sqrt(dis); 
	      } 
		  else { 
			  d[i][j] = d[j][i] = 2147483647; 
		  } 
	   } 
   }

   for (i = 1; i <= n; i++) 
     d[i][i] = 0; 

   for (k = 1; k <= n; k++) {
	   for (i = 1; i <= n; i++) {
		   if (d[i][k] != 2147483647) {
			   for (j = 1; j <= n; j++){ 
				   if (d[k][j] != 2147483647) {
                        if (d[i][k] + d[k][j] < d[i][j]) 
                           d[i][j] = d[i][k] + d[k][j]; 
				   }
			   }
		   }
	   }
   }
   dis = -1; 
   for (i = 1; i <= n; i++){ 
	   for (j = 1; j <= n; j++) {
		 if(d[i][j]>2147483646) {
			 printf("Send Kurdy\n");
			 return;
		 }
         if ((d[i][j] > dis) && (d[i][j] != 2147483647) && (i != j)) 
            dis = d[i][j]; 
	   }
   }
	printf("%.4lf\n",dis);
}

int main() {
	//freopen("c:\\h.txt","r",stdin);
	scanf("%d", &h); 
	for (t = 1; t <= h; t++) { 
         ReadData(); 
         printf("Case #%d:\n", t); 
         MakeSolu(); 
         putchar('\n'); 
     } 
	return 0; 
} 

