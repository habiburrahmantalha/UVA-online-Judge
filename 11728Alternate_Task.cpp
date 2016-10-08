#include<stdio.h>
#include<string.h>
#include<math.h>

bool prime[1010];
int SOD[1010];
void sieve()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(i=2;i<1000;i++)
    {
        if(prime[i])
        for(j=i+i;j<1000;j+=i)
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
    int i,x,tc=1;
    bool f;
    SOD[1]=1;
    for(i=2;i<1000;i++)
    {
        SOD[i]=sumofdiv(i);
    }
    //for(i=2;i<10;i++)
    //printf("%d\n",SOD[i]);

    while(scanf("%d",&x) && x)
    {
        f=false;
        for(i=x;i>=0;i--)
        if(SOD[i]==x)
        {
            printf("Case %d: %d\n",tc++,i);
            f=true;
            break;
        }
        if(f==false)
        printf("Case %d: -1\n",tc++);

    }
    return 0;

}
