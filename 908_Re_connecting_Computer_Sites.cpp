#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++) //for loop :P
#include<algorithm>
using namespace std;

int n,m,res1,res2;
int P[1000005];
vector<pair<int,pair<int,int> > > graph;  //graph (weight,a,b )

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
    res2=0;
    REP(i,0,m)
    {

        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {
            res2+=graph[i].first;
            P[pu]=P[pv]; //find circle
        }

    }
}

int main()
{
    int i,k,a,b,c;
    bool f=false;
    while(scanf("%d",&m)==1)
    {
        if(f)printf("\n");
        res1=res2=0;
        REP(i,0,m-1)
        {
            scanf("%d %d %d",&a,&b,&c);
            n=max(max(a,b),n);
            graph.push_back(make_pair(c,make_pair(a,b)));
            res1+=c;
        }
        scanf("%d",&k);
        REP(i,0,k)
        {
            scanf("%d %d %d",&a,&b,&c);
            n=max(max(a,b),n);
            graph.push_back(make_pair(c,make_pair(a,b)));
        }
        scanf("%d",&k);
        REP(i,0,k)
        scanf("%d %d %d",&a,&b,&c);
        sort(graph.begin(),graph.end());
        reset();
        krushkal();
        printf("%d\n%d\n",res1,res2);
        graph.clear();
        f=true;
    }
    return 0;
}
