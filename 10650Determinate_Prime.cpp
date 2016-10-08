#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define RANGE 32000


bool *prime=(bool*)calloc(RANGE, 1);
int *dprime=(int*)calloc(RANGE, 1);

int sieve()
{
	int i,j;
	for(i=2;i<=RANGE;i++)
		prime[i]=1;

	double lim=sqrt(RANGE);
	for ( i = 2;i <= lim; i ++ )
	{
		if ( prime[i] )
		{
			for ( j = i + i; j <= RANGE; j += i )
				prime[j] = 0;
		}
	}

    //int index=1;
    int a=2;
	for(i=1;i<= RANGE;i++)
	{
	    //if(index==10010)
	    //break;
		if(prime[i])
		{
		    dprime[i]=i-a;
		    a=i;
		}
		//primek[index++]=i;
	}
	for(i=1;i<= RANGE;i++)
	{
	    if(dprime[i])
	}
for(i=1;i<= 100;i++)
if(dprime[i])
	printf("%d %d\n",i,dprime[i]);
	return 0;
}

int main(void)
{
    sieve();

	free(prime);
}

