#include<stdio.h>

long long f[70];
void fib()
{
    int i;
    f[1]=1;
    f[2]=1;
    f[3]=1;
    for(i=4;i<70;i++)
        f[i]=f[i-1]+f[i-2]+f[i-3];
}
int main()
{
    fib();
    int t=1,n;
    while(scanf("%d",&n) && n)
        printf("Case %d: %lld\n",t++,f[n]);
        return 0;
}
