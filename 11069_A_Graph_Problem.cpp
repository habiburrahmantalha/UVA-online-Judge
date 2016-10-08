#include<stdio.h>

long long a[80];

void precal()
{
    int i;
    a[0]=0;
    a[1]=1;
    a[2]=a[3]=2;
    a[4]=3;
    a[5]=4;
    for(i=6;i<=76;i++)
    a[i]=a[i-1]+a[i-5];
}
int main()
{
    int n;
    precal();
    while(scanf("%d",&n)==1)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}
