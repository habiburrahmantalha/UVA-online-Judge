#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

int prime[10010];
vector<int>p;
vector<int>pf[10010];
void sieve()
{
    int i,j;

    memset(prime,1,sizeof(prime));

    prime[0]=prime[1]=0;

    for(i=2;i<=1000;i++)
    {
        if(prime[i])
        for(j=i+i;j<=1000;j+=i)
        prime[j]=0;
    }
    for(i=2;i<=1000;i++)
    if(prime[i])
    p.push_back(i);
}
void prime_factor()
{
    int i,j;
    for(i=4;i<=1000;i++)
    {
        for(j=0;p[j]<=i/2;j++)
        if(i%p[j]==0)
        pf[i].push_back(p[j]+i);
    }
}
int visit[10010],d[10010];

void dijkstra(int s,int t)
{
    priority_queue<pair<int,int> > pq;
    int u,v,i;
    memset(visit,0,sizeof(visit));
    memset(d,0x7F,sizeof(d));
    d[s]=0;
    visit[s]=1;
    pq.push(make_pair(0,s));
    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();
        visit[u]=1;
        for(i=0;i<pf[u].size();i++)
        {
            v=pf[u][i];
            if(d[v]>d[u]+1 && v<=1000)
            {
                d[v]=d[u]+1;
                pq.push(make_pair(-d[v],v));
            }
        }
    }

}
int main()
{
    sieve();
    prime_factor();
    int i,j,s,t,tc=1;

    while(scanf("%d %d",&s,&t)==2 && s+t)
    //for(s=1;s<=100;s++)
    //for(t=1;t<=1000;t++)
    {
        dijkstra(s,t);

        if(visit[t])
        printf("Case %d: %d\n",tc++,d[t]);
        else
        printf("Case %d: -1\n",tc++);

    }
    return 0;
}
