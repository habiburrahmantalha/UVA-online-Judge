#include<stdio.h>
#include<queue>

using namespace std;

long long W[100000+5],cost;
queue<long long>q;

long long abs(long long a)
{
    if(a<0)
        return -a;
    else
        return a;
}
void trade_wine(long long i)
{
    long long j;
    j=q.front();
    if(W[j]>abs(W[i]))
    {
        W[j]+=W[i];
        cost+=abs(W[i])*abs(i-j);
        W[i]=0;
    }
    else if(W[j]<abs(W[i]))
    {
        W[i]+=W[j];
        cost+=abs(W[j])*abs(i-j);
        W[j]=0;
        q.pop();
    }
    else
    {
        cost+=abs(W[j])*abs(i-j);
        W[i]=W[j]=0;
        q.pop();
    }
}

int main()
{
    long long n,i;
    while(scanf("%lld",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&W[i]);
            if(W[i]>0)
                q.push(i);
        }
        cost=0;
        for(i=0;i<n;i++)
        {
            if(W[i]<0)
            {
                trade_wine(i);
                i--;
            }
        }
        printf("%lld\n",cost);

    }
    return 0;
}
