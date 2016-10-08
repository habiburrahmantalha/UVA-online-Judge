#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

#define FOR(i,x,y) for(i=x;i<y;i++)
#define edge(a,b) make_pair(a,b)

int P[200010],R[200010],mst,cost,n,m;
vector<pair<int,pair<int,int> > > graph;

void reset()
{
    int i;
    FOR(i,0,n)
    {
        P[i]=i;
        R[i]=0;
    }
}

int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];
}

void unionset(int px,int py)
{

    if(R[px]>R[py])
        P[py]=px;
    else
        P[px]=py;
    if(R[px]==R[py])
        R[py]=R[px]+1;
}

void krushkal()
{
    int i,pu,pv;
    mst=cost=0;
    FOR(i,0,m)
    {
        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {
            unionset(pu,pv);
            cost+=graph[i].first;
            mst++;
            if(mst==n-1)
                break;

        }
    }
}
int main()
{
    int i,sum,a,b,c;
    while(scanf("%d %d",&n,&m))
    {
        sum=0;
        if(n==0 && m==0)
            break;

        FOR(i,0,m)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph.push_back(make_pair(c,edge(a,b)));
            sum+=c;
        }
        reset();
        sort(graph.begin(),graph.end());
        krushkal();
        printf("%d\n",sum-cost);
        graph.clear();

    }
    return 0;
}
