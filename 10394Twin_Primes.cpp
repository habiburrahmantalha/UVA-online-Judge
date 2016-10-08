#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define N 20000000



//bool *prime=(bool*)malloc(N*sizeof(bool));
bool *prime=(bool*)calloc(N, 1);
int twin[1000000],M;

int sieve()
{
	int i,j;
	for(i=2;i<=N;i++)
		prime[i]=1;

	double lim=sqrt(N);
	for ( i = 2;i <= lim; i ++ )
	{
		if ( prime[i] )
		{
			for ( j = i + i; j <= N; j += i )
				prime[j] = 0;
		}
	}
	int in=1;
	M=N-1590000;
	for(i=3;i<M;i++)
	{
	    if(prime[i] and prime[i+2])
	    twin[in++]=i;
	}
	//printf("%d\n",in);
	//int count=0;
    //for ( i = 2;i <= N; i ++ )
    //if(prime[i])
    //count++;
    //printf("%d\n",count);



}

int main(void)
{
    sieve();
    int x;
    while(scanf("%d",&x)==1)
    printf("(%d, %d)\n",twin[x],twin[x]+2);
	free(prime);
}
