#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define N 10010
vector<int>g[N],rg[N];
int ind,in[N],comp[N],visit[N],sortV[N],n;

void reset()
{
    int i;
    for(i=0;i<=n;i++)
    {
        g[i].clear();
        rg[i].clear();
    }
    memset(visit,0,sizeof(visit));
    memset(in,0,sizeof(in));
}

void dfs_forward(int u)
{
    int i,v;
    visit[u]=1;
    for(i=0;i<g[u].size();i++)
    {
        v=g[u][i];
        if(visit[v]==0)
        dfs_forward(v);
    }
    sortV[ind--]=u;
}
void dfs_reverse(int u,int V)
{
    int i,v;
    visit[u]=0;
    comp[u]=V;
    for(i=0;i<rg[u].size();i++)
    {
        v=rg[u][i];
        if(visit[v])
        dfs_reverse(v,V);
    }
}

int main()
{
    int t=1,tc,a,b,m,C,cnt,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        reset();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            rg[b].push_back(a);
        }

        ind=n-1;
        for(i=1;i<=n;i++)
        if(visit[i]==0)
        dfs_forward(i);

        C=0;
        for(i=0;i<n;i++)
        if(visit[sortV[i]])
        dfs_reverse(sortV[i],++C);

        for(i=1;i<=n;i++)
        for(j=0;j<g[i].size();j++)
        if(comp[i]!=comp[g[i][j]])
        in[comp[g[i][j]]]=1;

        cnt=0;
        for(i=1;i<=C;i++)
        if(in[i]==0)
        cnt++;
        printf("Case %d: %d\n",t++,cnt);
    }
    return 0;
}
