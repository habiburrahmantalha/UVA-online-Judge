#include<stdio.h>
#include<string.h>

long long x[1000010];

long long r(long long i)
{
    if(i==1)
    return 0;
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
    long long i,mx,j,k,l,temp;
    memset(x,0,sizeof(x));
    x[1]=3;
    for(i=1;i<1000001;i++)
        r(i);

    while(scanf("%lld %lld",&i,&j))
    {
        if(i==0 && j==0)
        break;
        if(i>j)
        {
            i^=j;
            j^=i;
            i^=j;
        }

        mx=0;
        for(l=i;l<=j;l++)
        if(l<1000001 && mx<x[l])
        {
            mx=x[l];
            k=l;
        }
        else
        {
            temp=r(l);
            if(mx<temp)
            {
                mx=temp;
                k=l;
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n",i,j,k,mx);

    }
    return 0;

}
