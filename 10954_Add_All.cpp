#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    priority_queue<long long>pq;
    long long cost,i,n,sum,x,a,b;

    while(scanf("%lld",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            pq.push(-x);
        }
        cost=0;
        while(pq.size()>1)
        {
            a=pq.top();pq.pop();
            b=pq.top();pq.pop();
            sum=a*(-1)+b*(-1);
            cost+=sum;
            pq.push(-sum);
        }
        pq.pop();
        printf("%lld\n",cost);
    }
    return 0;
}
