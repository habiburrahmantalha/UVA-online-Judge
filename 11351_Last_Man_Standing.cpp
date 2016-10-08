#include<stdio.h>

int josephus(int n,int k)
{
    if(n==1)
    return 0;
    else
        return (josephus(n-1,k)+k)%n;
}
long long f(long long  n,long long k)
{
    long long i,t[n+5];
    t[1]=0;
    for(i=2;i<=n;i++)
    {
        t[i]=(t[i-1]+k)%i;
        //printf("%d ",t[i]);
    }

    return t[n];

}
int main()
{
    long long tc,t=1,n,k;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&n,&k);
        //printf("Case %d: %d\n",t++,josephus(n,k));
        printf("Case %lld: %lld\n",t++,f(n,k)+1);
    }
    return 0;
}
