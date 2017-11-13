#include<stdio.h>
#include<string.h>


char D[1000],str[1000],str1[1000],str2[1000],F[1000],str3[1000];
int m;

void Rev(char X[]){
    int i,j,num;
    for(i=0,j=strlen(X)-1;i<=j; i++,j--){
        num=X[i];
        X[i]=X[j];
        X[j]=num;
     }
 }

void Add(){
     int p,n;
     n=strlen(str)-1;
     if(m>=1){
       p=m;
       while(p--)
          str[++n]='0';
     }
     Rev(str1);
     int i,j,carry=0,k;
     i=strlen(str)-1;
     j=strlen(str1)-1;
     for(k=0; i>=0||j>=0; k++,i--,j--){
        int u,v;
        if(i>=0)
          u=str[i]-'0';
        else
            u=0;
        if(j>=0)
          v=str1[j]-'0';
        else
            v=0;
        str2[k]='0'+(u+v+carry)%10;
        carry=(u+v+carry)/10;
    }
   if(carry>0)
      str2[k++]='0'+carry;
      str2[k]='\0';
      strcpy(str1,str2);
     m++;
    memset(str,0,1000);

}
void mul(char S[]){
     int i,j,carry,l;

     for(i=strlen(S)-1;i>=0; i--){
         l=carry=0;
        for(j=strlen(D)-1; j>=0; j--){
           str[l++]='0'+(carry+(D[j]-'0')*(S[i]-'0'))%10;
           carry=(carry+(S[i]-'0')*(D[j]-'0'))/10;
         }
        if(carry>0)
          str[l++]='0'+carry;
       Rev(str);
       Add();

    }
  strcpy(D,str1);
  Rev(D);
  m=0;
 memset(str1,0,1000);
}
void mul1(char S[]){
     int i,j,carry,l;

     for(i=strlen(S)-1;i>=0; i--){
         l=carry=0;
        for(j=strlen(D)-1; j>=0; j--){
           str[l++]='0'+(carry+(D[j]-'0')*(S[i]-'0'))%10;
           carry=(carry+(S[i]-'0')*(D[j]-'0'))/10;
         }
        if(carry>0)
          str[l++]='0'+carry;
       Rev(str);
       Add();

    }
  strcpy(F,str1);
   Rev(F);
  m=0;
  memset(str1,0,1000);
}
void Add1(char G[]){
int i,j,carry=0,k;
     i=strlen(G)-1;
     j=strlen(F)-1;
     for(k=0; i>=0||j>=0; k++,i--,j--){
        int u,v;
        if(i>=0)
          u=G[i]-'0';
        else
            u=0;
        if(j>=0)
          v=F[j]-'0';
        else
            v=0;
        str2[k]='0'+(u+v+carry)%10;
        carry=(u+v+carry)/10;
    }
   if(carry>0)
      str2[k++]='0'+carry;
      str2[k]='\0';
      strcpy(str3,str2);
      Rev(str3);
    memset(str2,0,1000);

}

int main(){
   int i,a,b;
      char B[10],A[10],K[10];
      while(scanf("%d%d",&a,&b)==2){
        m=0;
         memset(str1,0,1000);
         memset(str2,0,1000);
        if(b==0){
             printf("0\n");
             continue;
         }
		else if(a==1){
			printf("%d\n",b);
			continue;
		}

		else{
           sprintf(B,"%d",b);
             strcpy(K,B);
          for(i=2;i<=a; i++){
            if(i==2){
              sprintf(A,"%d",i);
              strcpy(D,B);
              mul(B);
		    mul1(A);
             Add1(B);
            }
            else{
               sprintf(A,"%d",i);
               mul(K);
		     mul1(A);
               Add1(str3);
		  }

         }
      }
     printf("%s\n",str3);
      memset(str3,0,1000);   
	  }
	return 0;

}

