#include<stdio.h>

 main()
 {
    int day[3652],i,wd,hd,kase,k,d,p,j,par[103],thd,work_day;
    scanf("%d",&kase);
    for(k=1;k<=kase;k++)
    {
	scanf("%d",& d);
	wd=0; hd=0; thd=0;
	for(i=1;i<=d;day[i]=1,i++);
	for(i=6;i<=d;i+=7)
	   day[i]=0;
	for(i=7;i<=d;i+=7) day[i]=0;
	for(i=1;i<=d;i++)
	 if(day[i]) hd++;
	scanf("%d",& p);
	for(j=0;j<p;j++)
	 scanf("%d",& par[j]);
	for(j=0;j<p;j++)
	  for(i=par[j];i<=d;i+=par[j])
	    day[i]=0;
	for(i=1;i<=d;i++)
	 if(day[i])
	  thd++;
	work_day=hd-thd;
	printf("%d\n",work_day);
    }
    return 0;
 }


