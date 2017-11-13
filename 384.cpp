#include<stdio.h>
#include<string.h>

char S[70];

int Sl(int i,int time) {
	int x;
    if(i>= strlen(S)) return -1;
	if(S[i] == 'D'|| S[i] == 'E'){
		if(S[i+1] != 'F') return -1;
		x = Sl(i+1,time);
		return x;
	}
	else if(S[i] =='F'){
		if(S[i+1] != 'F' && S[i+1] != 'G' && S[i+1] != 'E' && S[i+1] != 'D')
			return -1;
		if(S[i+1] == 'G'){
			if(time == 2 && (i+1) == strlen(S)-1)
			  return i+1;
		    if(time == 1) return i+1;
			return -1;
		}
		x = Sl(i+1,time); 
			return x;
	}
	return -1;
}

int Slimp(int i) {
   int x;
	if(i == 0 && S[i] != 'A') return -1;
   else if(S[i] == 'A'&& S[i+1] =='H') return i+1;
   else if(S[i] == 'A' && S[i+1] == 'B') {
	   if(S[i+2] != 'A') return -1;
	   x = Slimp(i+2);
	   if(x != -1 && S[x+1] == 'C')
	     return x+1;
	   else return -1;
   }
   else if(S[i] == 'A'){
	   if(S[i+1] != 'D' && S[i+1] != 'E') return -1;
	   x = Sl(i+1,1);
	   if(x != -1 && S[x+1] == 'C') 
		   return x+1;
	   else return -1;
   }
   return -1;
	 
}


void Cal() {
   int x;
   x = Slimp(0);
   if(x == -1){ printf("NO\n"); return;}
   x = x+1;
   if(Sl(x,2) == -1) { printf("NO\n"); return; }
   printf("YES\n");
}
int main() {

	int kase;
	scanf("%d",&kase);
	printf("SLURPYS OUTPUT\n");
	while(kase--) {
		scanf("%s",S);
        Cal();  
		
	}
    printf("END OF OUTPUT\n");
	return 0;

}
