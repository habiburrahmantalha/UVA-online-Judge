#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++) //for loop :P
using namespace std;

int n,m,mst,ac,cost,cnt,e;
int P[10010];
vector<pair<int,pair<int,int> > > graph;  //graph (weight,a,b )

void reset() //reset parent
{
    int i;
    REP(i,0,n+1) P[i] = i;
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

    REP(i,0,e)
    {

        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {

            P[pu]=P[pv]; //find circle
            cost+=graph[i].first;
            mst++;
            if(mst==n-1)
            break;
        }

    }
    REP(i,1,n+1)
    if(P[i]==i)
    {

        cnt++;
        cost+=ac;
    }

}

int main()
{
    int i,a,b,c,tc,t=1;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&n,&m,&ac);
        if(n==0 && m==0)
            break;
        reset();
        e=0;
        REP(i,0,m)
        {
            scanf("%d %d %d",&a,&b,&c);
            if(c<ac)
            {
                graph.push_back(make_pair(c,make_pair(a,b)));
                e++;
            }
        }
        sort(graph.begin(),graph.end());
        cost=cnt=0;
        krushkal();

        printf("Case #%d: %d %d\n",t++,cost,cnt);


        graph.clear();
    }
    return 0;
}

