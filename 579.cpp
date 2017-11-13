#include<stdio.h>
#include<math.h>

float h,m;
main()
{
     float th;
     float dh,dm,p_angle,d_angle;
     int k,i;
     k=0;

     while(1)
     {
	   scanf("%f:%f",&h,&m);
	   if(h==0)
	   if(m==0)  break;


     	 th=fmod(h,12)*5;
	 dh=th*6;
	 dm=m*6;
	 d_angle=(m/12)*6;
	 dh=dh+d_angle;

	if(dh>=dm)
	{
	    p_angle=dh-dm;
	    if(p_angle>180)
	      printf("%.3lf\n",360-p_angle);
	    else
	      printf("%.3lf\n",p_angle);
	}
	else
	{
	   p_angle=dm-dh;
	   if(p_angle>180) printf("%.3lf\n",360-p_angle);
	   else printf("%.3lf\n",p_angle);
	}
     }
    return 0;
}


