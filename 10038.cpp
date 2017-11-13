#include<stdio.h>
#include<math.h>

int a[3005];
char cheack[3002];

main()
{
    int i,j,k,n;
    while(scanf("%d", &n) == 1) {
      for(i = 0; i<n; i ++)
	scanf("%d", &a[i]);
      for(i = 1; i<n; i++)   cheack[i] = 0;

      for(i = 0; i<n-1; i ++) {
	k = abs(a[i]-a[i+1]);
	if(cheack[k])  {
	  printf("Not jolly\n");
	  goto done;
	}
	else
	  cheack[k] = 1;
      }
      for(i = 1; i<n; i++)
	if(!cheack[i]) {
	  printf("Not jolly\n");
	  goto done;
	}
      printf("Jolly\n");
      done:;
    }
    return 0;
}

