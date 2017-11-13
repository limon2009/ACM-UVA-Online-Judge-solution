#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[200],b[200],d[200];
char fibs[500][110],first[200],scend[200];
int k,digit[500];

int fbs()
{
     int sum,c,ck,l,i;
     for(i = 0; i <108; i ++)  a[i] = b[i] = d[i] = 0;
     b[0]  = 1;
       ck  = 0;
	 k = 0;

     for(i = 0; i<482; i ++)
     {
	      sum = 0;
		k = 0;
		c = 0;
	   while(1)
	   {
	      sum =a[k] + b[k] + c;
	      if(!sum && ck <= k) break;
	      d[k] = sum % 10;
	      c = sum / 10;
	      k ++;
	   }

	   digit[i] = k;
	   for(l = 0;l<k; l ++)
	   {
	      b[l]=a[l];
	      a[l]=d[l];
	      fibs[i][l] = d[l];
	   }
	   ck = k;

     }

    return 0;
}


int big(int p,int q) {

  int i,k = 0;
  if(p<digit[q]) return 1;
  for(i = p-1; i >= 0; i --) {
    if(fibs[q][i]>first[k])  return 1;
    else if(fibs[q][i]<first[k]) return 0;
    k++;
  }
  return 1;
}

int sort(int p,int q) {

  int i,k = 0;
  if(digit[q]>p) return 0;
  if(digit[q]<p) return 1;
  for(i = p-1; i>=0; i --) {
    if(fibs[q][i] > scend[k]) return 0;
    else if(fibs[q][i] < scend[k] ) return 1;
    k ++;
  }
  return 1;
}



int main()
{
       int fib,dig1,dig2,i;

       fbs();

       while(1)
       {
	    scanf("%s%s", first,scend);
	    fib = 0;
	    dig1 = strlen(first);
	    dig2 = strlen(scend);
	    if(dig1 == 1 && dig2 == 1)
	      if(first[0] == '0' && scend[0] == '0' ) break;

	    for(i = 0; first[i]; i ++)  first[i] = first[i] - 48;
	    for(i = 0; scend[i]; i ++)  scend[i] = scend[i] - 48;
	    if(first[0] == 0 && scend[0] != 0 )
	       first[0] = 1;

	    if(dig1 == 1)
	      if(first[0] == 1)
		fib --;

	    for(i = 0; i<482; i ++) {

	      if(dig2 < digit[i])   break;
	      if(dig1 > digit[i])  continue;

	      if(digit[i]>dig1 && digit[i]<dig2) fib ++;
	      else if(digit[i]>= dig1 || digit[i]<= dig2) {

		 if(big(dig1,i)) {

		   if(sort(dig2,i))
		     fib ++;
		   else
		     break;
		 }
	      }
	    }

	    printf("%d\n",fib);
       }

 return 0;
}
