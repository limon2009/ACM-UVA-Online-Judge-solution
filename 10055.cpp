#include<stdio.h>



int main() {

	   double h,o;
	   while(scanf("%lf%lf",&h,&o) == 2) {
		    
	      if(h>=o) printf("%.0lf\n",h-o);
		  else 
			  printf("%.0lf\n",o-h);
	   }

	   return 0;
}
