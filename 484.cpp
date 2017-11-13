#include<stdio.h>
#include<string.h>

char a[1000000][20];

main()
{
	int k=0,j,i,c;
	while(scanf("%s",&a[k])==1)
		k++;
    
	for(i = 0; i<k; i++)
	{
		if(strcmp(a[i],"#"))
		{   
			c = 0;
			printf("%s",a[i]);
		    for(j = i+1; j<k; j++)
			{
				if(!strcmp(a[i],a[j]))
				{
					c++;
					strcpy(a[j],"#");
				}
			}
			printf(" %d\n",c+1);
		}

	}
	return 0;
}
