#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#define N 1000000


bool *prime=(bool*)calloc(N, 1);
//bool *dprime=(bool*)calloc(N, 1);
int dprime[N];

int sieve()
{
	int i,j;
	memset(dprime,0,sizeof(dprime));
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
	int x,sum,in=1;

    for(i=2;i<N;i++)
    {
        x=i;
        sum=0;
        if(prime[i])
        {
            while(x)
            {
                sum+=x%10;
                x/=10;
            }
        }
        if(prime[sum])
        dprime[i]=in++;
    }
    //for(i=2;i<100;i++)
    //if(dprime[i])
    //printf("%d %d\n",i,dprime[i]);



}

int main()
{
    sieve();
    int t,t1,t2,i,j,k;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",&t1,&t2);
        if(t1!=1)
        {
            for(j=t1; ;j--)
            if(dprime[j])
            break;
        }
        else
        j=0;
        for(k=t2; ;k--)
        if(dprime[k])
        break;
        if(j<t1)
        printf("%d\n",dprime[k]-dprime[j]);
        else
        printf("%d\n",dprime[k]-dprime[j]+1);


    }
    free(prime);

    return 0;
}
