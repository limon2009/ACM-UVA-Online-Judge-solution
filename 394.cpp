#include<stdio.h>
#include<string.h>

char ary[20][20];
int base[20],size[20],n_dy[30];
int dym[20][40],indexx,pos[30];

int calculate() {

     int i,j,k,m,L[30],pos_1[20];
     int address;

     k = n_dy[indexx];
     m = 0;

     for(j = 0; j<k*2; j += 2) {
	pos_1[m] = pos[m] - dym[indexx][j];
	m ++;
     }
     m = 0;
     for(j = 0; j<k*2; j += 2)
       L[m++] = dym[indexx][j+1] - dym[indexx][j] + 1;

    if(k == 1 )
       address = pos_1[0];

    else if( k == 2)
      address = pos_1[0] * L[1] + pos_1[1];

    else {

       address = L[1] * pos_1[0] + pos_1[1];
       for(i = 2; i<k; i ++)
	 address = address * L[i] + pos_1[i];
    }


    address = size[indexx] * address + base[indexx];

    printf("%s[",ary[indexx]);
    for(i = 0; i<k; i ++) {
       printf("%d",pos[i]);
       if(i < k-1)
	 printf(", ");
    }
    printf("] = %d\n",address);

    return 0;
}


int main()  {

   int i,j,k,name,test;
   char n_ary[15];

   scanf("%d%d", &name, &test);

   for(i = 0; i<name; i ++) {
      scanf("%s%d%d%d",ary[i], &base[i], &size[i], &n_dy[i]);
      for(j = 0; j < n_dy[i]*2; j ++)
	 scanf("%d", &dym[i][j]);
  }

  for(i = 0; i<test; i ++) {
      scanf("%s",n_ary);
      for(j = 0; j<name;  j ++)
	if(!strcmp(n_ary,ary[j]))
	  break;
     k = n_dy[j];
     indexx = j;
     for(j = 0; j<k; j ++)
	   scanf("%d", &pos[j]);
     calculate();
  }
  return 0;
}
