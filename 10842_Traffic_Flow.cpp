#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++) //for loop :P
using namespace std;

int n,m,mst;
int P[110];
vector<pair<int,pair<int,int> > > graph;  //graph (weight,a,b )
vector<int>MST;
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
    for(i=m-1;i>=0;i--)
    {

        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {
            MST.push_back(graph[i].first);
            P[pu]=P[pv]; //find circle
            mst++;
            if(mst==n-1)
            break;
        }

    }
}

int main()
{
    int i,a,b,c,tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);

        reset();
        REP(i,0,m)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(graph.begin(),graph.end());
        krushkal();
        printf("Case #%d: %d\n",t++,MST[MST.size()-1]);
        MST.clear();
        graph.clear();
    }
    return 0;
}
