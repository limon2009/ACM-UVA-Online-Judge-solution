#include<stdio.h>

void PRINT2() {
	printf("00\n");
	printf("01\n");
	printf("81\n");
}

void PRINT4() {
	printf("0000\n");
	printf("0001\n");
	printf("2025\n");
	printf("3025\n");
	printf("9801\n");
}

void PRINT6() {
	printf("000000\n");
	printf("000001\n");
	printf("088209\n");
              printf("494209\n");
	printf("998001\n");
}

void PRINT8() {
	printf("00000000\n");
	printf("00000001\n");
	printf("04941729\n");
              printf("07441984\n");
              printf("24502500\n");
	printf("25502500\n");
	printf("52881984\n");
	printf("60481729\n");
	printf("99980001\n");

}	


int main()  {
	int N;
	while(scanf("%d",&N) == 1)   {
		
		switch(N)  {
		case 2:
				  PRINT2();
		          break;
		case 4:
				  PRINT4();
		          break;
		case 6:
				  PRINT6();
		          break;
		case 8:
				  PRINT8();
			      break;
		}

	}
        
	return 0;

}
