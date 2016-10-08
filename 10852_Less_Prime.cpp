#include<stdio.h>
#include<string.h>

#define N 10010
bool prime[N+5];
int less_prime[N+5],p[N+5];

void sieve()
{
    int i,j,k;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(i=4;i<=N;i+=2)
    prime[i]=false;
    for (i = 3; i * i <= N; i++ )
    {
        if ( prime[i] )
        {
            for (j = i * i; j <= N; j += 2 * i )
                prime[j] = false;
        }
    }
    memset(less_prime,0,sizeof(less_prime));
    for(i=2;i<=N;i++)
    {
        if(prime[i])
        for(j=1;j*i<=N;j++)
        {
            for(k=j*i;k<(j+1)*i;k++)
            if(k<=N)
            if(less_prime[k]==0)
            {
                less_prime[k]=i;
                p[k]=j;
            }
            else if((k-p[k]*i)<(k-j*i))
            {
                less_prime[k]=i;
                p[k]=j;
            }
        }
    }
    /*
    int c=0;
    for(i=0;i<=N;i++)
    if(less_prime[i])
    //c++;
    printf("%d ",i);
    */
}

int main()
{
    sieve();
    int tc,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("%d\n",less_prime[n]);
    }
    return 0;
}
