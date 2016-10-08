#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++) //for loop :P
using namespace std;

int n,m,mst;
int P[1010];
vector<pair<int,pair<int,int> > > graph;  //graph (weight,a,b )
vector<int>edge;
void reset() //reset parent
{
    int i;
    REP(i,0,n) P[i] = i;
}
int findset(int x)  //find parent
{
    if(x != P[x])
        P[x] = findset(P[x]);
    return P[x];
}

void krushkal()
{
    int i,pu,pv;
    mst=0;
    REP(i,0,m)
    {

        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {
            P[pu]=P[pv]; //find circle

        }
        else
            edge.push_back(graph[i].first);

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
        if(edge.size()==0)
            printf("forest\n");
        else{
            for(i=0;i<edge.size()-1;i++)
                printf("%d ",edge[i]);
            printf("%d\n",edge[i]);
        }
        graph.clear();
        edge.clear();
    }
    return 0;
}
