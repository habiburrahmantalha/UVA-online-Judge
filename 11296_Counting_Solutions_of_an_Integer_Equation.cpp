#include<stdio.h>
#define N 1000001
long long res[N+5];
void precal()
{
    /*
    int i,j,k;

    for(i=0;i<=N;i++)
    {
        for(j=0;i+j*2<=N;j++)
        {
            for(k=0;i+2*j+2*k<=N;k++)
            //printf("%d = %d 2*%d 2*%d\n",i+2*j+2*k,i,j,k);
            res[i+2*j+2*k]++;
        }
    }
    for(i=0;i<=N;i++)
    printf("%d %d\n",i,res[i]);
    */
    long long  i,k;
    k=2;
    res[0]=res[1]=1;
    for(i=2;i<=N;i+=2,k++)
    res[i]=res[i+1]=res[i-1]+k;
}
int main()
{
    precal();
    long long n;
    while(scanf("%lld",&n)==1)
    {
        printf("%lld\n",res[n]);
    }
    return 0;
}
