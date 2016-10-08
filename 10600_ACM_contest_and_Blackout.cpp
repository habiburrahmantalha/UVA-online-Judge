#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++) //for loop :P
using namespace std;

int n,m,mst,cost,in;
int P[110];
vector<pair<int,pair<int,int> > > graph;  //graph (weight,a,b )
vector<int> C,MST[110];

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

void krushkal(int x)
{
    int i,pu,pv;
    bool f=false;;
    mst=cost=0;
    REP(i,0,m)
    {
        if(i!=x)
        {
            pu=findset(graph[i].second.first);
            pv=findset(graph[i].second.second);
            if(pu!=pv)
            {
                cost+=graph[i].first;
                MST[in].push_back(i);
                P[pu]=P[pv]; //find circle
                mst++;

                if(mst==n-1)
                    break;

            }
        }

    }

    //sort(MST[in].begin(),MST[in].end());

    if(in!=0 && MST[0]==MST[in])
       f=true;
    if(!f && mst==n-1)
    {
        //REP(i,0,MST[in].size())printf("%d ",MST[in][i]);
        //printf("%d %d*\n",x,cost);
        C.push_back(cost);
        in++;
    }
    else
        MST[in].clear();
}

int main()
{
    int i,a,b,c,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);


        REP(i,0,m)
        {
            scanf("%d %d %d",&a,&b,&c);
            graph.push_back(make_pair(c,make_pair(a,b)));
        }
        sort(graph.begin(),graph.end());

        in=0;
        REP(i,-1,m)
        {
            reset();
            krushkal(i);
        }

        sort(C.begin(),C.end());
        printf("%d %d\n",C[0],C[1]);
        graph.clear();
        C.clear();
        REP(i,0,in)MST[i].clear();
    }
    return 0;
}
