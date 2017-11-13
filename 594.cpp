#include<stdio.h>
#include<math.h>

typedef long long ss;

char Bit[4][9];

void Convert( ss u) {
	int r = 0, c = 0;
	ss n;
	for(n = 2147483648; n; n =n>>1){
	   if(u & n) Bit[r][c++] = 1;
	   else Bit[r][c++] = 0;
	   if(c == 8) { c = 0; r ++; }
    }
}

void Reverse() {
   int i, j , f = 1, k , l;
   for(i = 0; i<4 && f; i++) {
          for(j = 7; j>=0; j--)
			  if(Bit[i][j] == 1) {  f = 0 ; break; }
   }
   for(k = i-1; k<4; k++){
	   for(l = j-1; l>=0; l--){
		   Bit[k][l] = !Bit[k][l];
	   }
	   j = 8;
   }

}

void GetRes() {
    int i, j , f = 0;
	int p = 0;
	ss sum = 0;
	if(Bit[3][0] == 1) { printf("-"); Reverse(); }
	for(i = 0; i<4; i++) {
		for(j = 7; j>=0; j--) {
		  sum += Bit[i][j] * pow(2,p++);
		}
	}
	printf("%lld\n",sum);
}
int main() {
   ss n;
   while(scanf("%lld",&n) == 1) {
      Convert(n);
	  printf("%lld converts to ",n);
	  GetRes();
	  
	  
   }
   
	return 0;

}
