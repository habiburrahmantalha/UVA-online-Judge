#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define RANGE 1000010




bool *prime=(bool*)calloc(RANGE, 1);


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


}

int main(void)
{
    //freopen("in.txt","r",stdin);
    sieve();
    int x,i,z;
    while(scanf("%d",&x) && x)
    {
        z=0;
        for(i=2;i<=x;i++)
        if(prime[i] && prime[x-i])
        {
            z=i;
            break;
        }
        if(z)
        printf("%d:\n%d+%d\n",x,z,x-z);
        else
        printf("%d:\nNO WAY!\n",x);
    }
	free(prime);
	return 0;
}
