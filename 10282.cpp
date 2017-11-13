#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s1[200];


typedef struct ppp
    {
	char word1[11];
	char word2[11];
    }sss;
sss store[100000],word;

int bs(const void *a, const void *b) {

   return strcmp( ((sss *)a)->word2, ((sss *)b)->word2);
}


int main(void)
{
	int i,j,k,t,l,c;
	sss *p;
	l = 0;
	while(1)
	{
		gets(s1);
		t=sscanf(s1,"%s%s",&store[l].word1,&store[l].word2);
		if(t<=0) break;
		l++;
	}
	qsort(store, l, sizeof(store[0]), bs);

	while(scanf("%s",&word.word2) != EOF)
	{

		p = (sss *) bsearch(&word, store, l, sizeof(store[0]), bs);

		if(p != NULL) printf("%s\n",p->word1);
		else printf("eh\n");
	}
	return 0;

}
