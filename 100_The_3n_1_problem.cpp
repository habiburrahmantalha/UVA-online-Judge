#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

long long x[1000010];

long long r(long long i)
{
    if(i<1000001 && x[i])
    return x[i];

    if(i&1)
    {
        if(i<1000001)
        return x[i]=r(3*i+1)+1;
        else
        return r(3*i+1)+1;
    }

    else
    {
        if(i<1000001)
        return x[i]=r(i/2)+1;
        else
        return r(i/2)+1;
    }

}
int main()
{
    long long i,mx,j,k,temp;
    memset(x,0,sizeof(x));
    x[1]=1;
    for(i=1;i<1000001;i++)
    {
        r(i);
        //printf("%d ",x[i]);
    }

    while(scanf("%lld %lld",&i,&j)==2)
    {
        printf("%lld %lld ",i,j);
        if(i>j)
        {
            temp=i;
            i=j;
            j=temp;
        }
        mx=0;
        for(k=i;k<=j;k++)
        if(mx<x[k])
        mx=x[k];
        printf("%lld\n",mx);
    }
    return 0;
}
