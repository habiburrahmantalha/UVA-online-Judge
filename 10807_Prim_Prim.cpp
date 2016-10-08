#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int P[11],visit[26],m,n,mn,vi[26][26],cnt,edge,ec[26][26];
vector<pair<int,pair<int,int> > >g;

void reset()
{
    int i;
    for(i=0;i<=n;i++)
    P[i]=i;
}
int find(int x)
{
    if(P[x]!=x)
    P[x]=find(P[x]);
    return P[x];
}

int kruskal()
{
    int u,v,i,mst=0,cost=0;
    reset();

    for(i=0;i<m;i++)
    {
        if(vi[g[i].second.first][g[i].second.second]==0)
        {
            u=g[i].second.first;
            v=g[i].second.second;
            if(u!=v)
            {
                P[u]=P[v];
                visit[i]=1;
                cost+=g[i].first;
                mst++;
                if(mst==n-1)
                break;
            }
        }
    }
    if(mst<n-1)
    return -1;
    else
    return cost;
}

int kruskal2()
{
    int u,v,i,mst=0,cost=0;
    reset();

    for(i=0;i<m;i++)
    {
        if(visit[i]==0)
        {
            u=g[i].second.first;
            v=g[i].second.second;
            if(u!=v)
            {
                P[u]=P[v];
                cost+=g[i].first;
                mst++;
                if(mst==n-1)
                break;
            }
        }
    }
    if(mst<n-1)
    return -1;
    else
    return cost;
}

void backtrack(int x)
{

    memset(visit,0,sizeof(visit));
    if(m-cnt>=2*n-2)
    {
        int a=kruskal();
        int b=kruskal2();
        if(a!=-1 && b!=-1)
        mn=min(mn,a+b);
        //printf("%d %d %d\n",a,b,mn);
        for(int i=x+1;i<m;i++)
        {
            if(vi[g[i].second.first][g[i].second.second]==0)
            {
                vi[g[i].second.first][g[i].second.second]=1;
                vi[g[i].second.second][g[i].second.first]=1;
                cnt+=ec[g[i].second.first][g[i].second.second];
                backtrack(i);
                cnt-=ec[g[i].second.first][g[i].second.second];
                vi[g[i].second.first][g[i].second.second]=0;
                vi[g[i].second.second][g[i].second.first]=0;
            }
        }
    }
}
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d",&m);
        memset(ec,0,sizeof(ec));
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g.push_back(make_pair(c,make_pair(a,b)));
            ec[a][b]++;
            ec[b][a]++;
        }
        sort(g.begin(),g.end());

        memset(visit,0,sizeof(visit));
        mn=2000000;


        memset(vi,0,sizeof(vi));
        cnt=0;
        backtrack(0);

        memset(vi,0,sizeof(vi));
        vi[g[0].second.first][g[0].second.second]=1;
        vi[g[0].second.second][g[0].second.first]=1;
        cnt+=ec[g[0].second.first][g[0].second.second];
        backtrack(0);


        if(mn==2000000)
        printf("No way!\n");
        else
        printf("%d\n",mn);


        g.clear();
    }
    return 0;
}
