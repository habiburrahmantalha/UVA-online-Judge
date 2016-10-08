#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++)
using namespace std;

int n,m;
int P[10000000];
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
void unionset(int x,int y)
{
    P[findset(x)]=findset(y);
}
bool sameset(int x,int y)
{
    return findset(x)==findset(y);
}
void krushkal()
{
    int i,mst=0;
    for(i=0;i<m;i++)
    {

        if(!sameset(graph[i].second.first,graph[i].second.second))
        {
            MST.push_back(graph[i]);
            unionset(graph[i].second.first,graph[i].second.second);
        }
        mst++;
        if(mst==n-1)
            break;
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
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(graph.begin(),graph.end());
        krushkal();
        sort(MST.begin(),MST.end());
        if(MST.size()!=n-1)
            printf("IMPOSSIBLE\n");
        else
        printf("%d\n",MST[MST.size()-1]);

        MST.clear();
        graph.clear();
    }
    return 0;
}
