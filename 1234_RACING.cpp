#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int P[10010],n,m;
long long cost;
vector<pair<int,pair<int,int> > > edge;

int find(int x)
{
    if(x!=P[x])
    P[x]=find(P[x]);
    return P[x];
}

void krushkal()
{
    int mst=0,i,u,v;
    cost=0;
    for(i=m-1;i>=0;i--)
    {
        u=find(edge[i].second.first);
        v=find(edge[i].second.second);
        if(u!=v)
        {
            P[u]=P[v];
            cost+=edge[i].first;
            mst++;
            if(mst==n-1)
            break;
        }
    }
}
int main()
{
    int tc,a,b,c,i;
    long long sum;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
        P[i]=i;
        sum=0;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            sum+=c;
            edge.push_back(make_pair(c,make_pair(a,b)));

        }
        sort(edge.begin(),edge.end());
        krushkal();
        printf("%lld\n",sum-cost);

        edge.clear();
    }

    return 0;
}
