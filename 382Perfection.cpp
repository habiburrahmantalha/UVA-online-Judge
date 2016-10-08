#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 60010

bool prime[N+10];

void sieve()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(i=2;i<N;i++)
    {
        if(prime[i])
        for(j=i+i;j<N;j+=i)
        prime[j]=false;
    }
    //for(i=0;i<1000;i++)
    //if(prime[i])
    //printf("%d ",i);

}

int sumofdiv(int n)
{
    if(prime[n])
    return n+1;
    int sod=1,i,a;
    for ( i = 2;i <= n; i ++ )
    {
        if(prime[i])
		{
		    a=0;
			while(n%i==0)
			{
				n=n/i;
				a++;
			}
            sod*=(pow(i,a+1)-1)/(i-1);
            if(n==1)
            return sod;
		}
    }
    sod*=(pow(n,a+1)-1)/(n-1);
    return sod;
}

int main()
{
    sieve();
    int n,x;
    printf("PERFECTION OUTPUT\n");
    while(scanf("%d",&n) && n)
    {
        x=sumofdiv(n);
        if(x==2*n)
        printf("%5d  PERFECT\n",n);
        else if(x<2*n)
        printf("%5d  DEFICIENT\n",n);
        else
        printf("%5d  ABUNDANT\n",n);

    }
    printf("END OF OUTPUT\n");
    return 0;
}

