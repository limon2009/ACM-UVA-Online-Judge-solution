#include<stdio.h>
#include<math.h>

char a[32009];
int store[700],m;
int p[6000];


int prime_table()   {

	 int i,j, k = 0;
	 for(i = 2; i <32000; i ++)  a[i] = 1;
	 for(i = 2; i <= sqrt(32000); )  {
		  for(j = i+i; j <32000; j += i)
			  a[j] = 0;
		  for(i ++; !a[i]; i ++);
	 }

	 for(i = 2; i <32000; i ++)
		 if(a[i])
 			 p[k++] = i;
   
	return 0;
}

  

int prime_fact(int n)  {

	int i,limit;
	m = 0;
	limit = sqrt(n);
	for(i = 0; p[i] <=limit; i ++) {
		if(n % p[i] == 0 ) {
			store[m++] = p[i];
			while( n % p[i] == 0) {
				n = n / p[i];
				if( n == 1)
					break;
			}
		}
		if(n == 1)
			break;
	}

    if( n != 1)
		store[m ++] = n;
	return 0;
}



int result(int n)   {

	int i,j;
	double frc,in;
	frc = n;
	for(i = 0; i<m; i ++) {
	    in = store[i];
	    frc = frc * ( 1 - 1 / in);
	}

	printf("%.0lf\n",frc);
	return 0;
}





int main()   {


	int n;
	prime_table();
	while(scanf("%d",&n) && n)  {

          prime_fact(n);
		  result(n);
		  
	}	
	return 0;
}
