#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++)
using namespace std;

int n,m,mx,mst;
int P[1000001];
vector<pair<int,pair<int,int> > > graph,MST;

void reset()
{
    int i;
    REP(i,0,n) P[i] = i;
}

int findset(int x)
{
    if(x==P[x])
        return x;
    else
    {
        P[x]=findset(P[x]);
        return P[x];
    }
}

void krushkal()
{
    int i,pu,pv;
    mx=mst=0;
    REP(i,0,m)
    {
        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {
            //MST.push_back(graph[i]);
            if(mx<graph[i].first)
                mx=graph[i].first;
            P[pu]=P[pv];
            mst++;
            if(mst==n-1)
                break;
        }

    }
}

int main()
{
    int i,a,b,c;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        reset();
        REP(i,0,m)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(graph.begin(),graph.end());
        krushkal();

        if(mst!=n-1)
            printf("IMPOSSIBLE\n");
        else
        printf("%d\n",mx);

        //MST.clear();
        graph.clear();
    }
    return 0;
}
