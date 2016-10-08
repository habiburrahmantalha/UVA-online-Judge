//Problem Type : LCA,prims
//Time : 3.656
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

vector<int> G[50010],C[50010];
int pi[50010],visit[50010],N,M,L[50010];
long long d[50010],mx;

void prims(int s)
{
    priority_queue<pair<int,pair<int,int> > >pq;

    int i,u,v,p;

    pq.push(make_pair(0,make_pair(s,s)));

    d[s]=0;
    L[s]=0;
    pi[s]=s;

    while(!pq.empty())
    {
        u=pq.top().second.first;
        p=pq.top().second.second;
        pq.pop();
        //if(visit[u]==0)
        //pi[u]=p;

        visit[u]=1;

        for(i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            if(visit[v]==0 && d[v]>C[u][i])
            {
                //printf("->%d %d\n",v,C[u][i]);
                d[v]=C[u][i];
                L[v]=L[u]+1;
                pq.push(make_pair(-d[v],make_pair(v,u)));

                pi[v]=u;
            }
        }
    }
    //for(i=1;i<=N;i++)
    //printf("%d %d %d\n",i,pi[i],d[i]);
}
bool path;
void max_path(int s,int t)
{
    if(s==t)
    return;
    else
    {
        if(d[s]>mx)
        mx=d[s];
        max_path(pi[s],t);
    }
}
int find_CA(int a,int b)
{
    if(a==b)
    return a;
    if(L[a]==L[b])
    return find_CA(pi[a],pi[b]);
    if(L[a]<L[b])
    return find_CA(a,pi[b]);
    else
    return find_CA(pi[a],b);
}
int main()
{
    int a,b,c,q,i,s,t,CA;
    bool f=false;
    while(scanf("%d %d",&N,&M)==2)
    {
        if(f)
        printf("\n");
        f=true;

        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            G[a].push_back(b);
            G[b].push_back(a);
            C[a].push_back(c);
            C[b].push_back(c);
        }
        memset(visit,0,sizeof(visit));
        memset(d,0x7F,sizeof(d));
        memset(pi,0,sizeof(pi));
        memset(L,0,sizeof(L));

        for(i=1;i<=N;i++)
        if(visit[i]==0)
        prims(i);
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&s,&t);
            mx=0;
            CA=find_CA(s,t);
            max_path(t,CA);
            max_path(s,CA);
            printf("%lld\n",mx);
        }
        for(i=0;i<=N;i++)
        {
            G[i].clear();
            C[i].clear();
        }
    }
    return 0;
}
