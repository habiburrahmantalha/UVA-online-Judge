#include<stdio.h>
#include <stdlib.h>

#define N 10000000

int *ndiv=(int*)malloc(N*sizeof(int));
//int *ndiv=(int*)calloc(N, 1);

void divisor()
{
    int i,j;
    for ( i = 1; i <= 1000000; i++ )
	{
		for ( j = i; j <= 1000000; j+=i )
			ndiv[j]+=1;
	}
}

int main()
{
    divisor();
    //int t,l,u;
    //scanf("%d",&t);
    //while(t--)
    {
        //scanf("%d %d",&l,&u);
        //printf("Between %d and %d, %d has a maximum of 4 divisors.\n");
    }
    return 0;
}
