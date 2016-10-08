#include<stdio.h>//dominos
#include<string.h>
#include<vector>
#include<stack>
using namespace std;

#define N 100010
bool cycle;
vector<int>g[N];
vector<int>rg[N],q[N];
int sortV[N],ind,visit[N],n,comp[N],in[N];


void dfsf(int u)
{
    visit[u]=2;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(visit[v]==2)
        cycle=true;
        if(visit[v]==0)
        dfsf(v);
    }
    visit[u]=1;
    sortV[ind--]=u;
}

void dfsr(int u,int V)
{
    visit[u]=0;
    comp[u]=V;
    for(int i=0;i<rg[u].size();i++)
    {
        int v=rg[u][i];
        if(visit[v]==1)
        dfsr(v,V);
    }
}
int main()
{
    int tc,m,i,j,a,b,c,cnt;
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d",&n,&m);

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            rg[b].push_back(a);
        }

        ind=n-1;;
        cycle=false;
        memset(visit,0,sizeof(visit));
        for(i=1;i<=n;i++)
        if(visit[i]==0)
        dfsf(i);

        if(cycle)
        {
            memset(comp,0,sizeof(comp));
            c=0;
            for(i=0;i<n;i++)
            if(visit[sortV[i]])
                dfsr(sortV[i],++c);


            memset(in,0,sizeof(in));
            for(i=1;i<=n;i++)
            for(j=0;j<g[i].size();j++)
            if(comp[i]!=comp[g[i][j]])
            in[comp[g[i][j]]]=1;

            cnt=0;
            for(i=1;i<=c;i++)
            if(in[i]==0)
            cnt++;

        }
        else
        {
            cnt=0;
            for(i=0;i<n;i++)
            {
                if(visit[sortV[i]])
                cnt++;
                visit[sortV[i]]=0;
                for(j=0;j<g[sortV[i]].size();j++)
                visit[g[sortV[i]][j]]=0;

            }
        }

        printf("%d\n",cnt);
        for(i=0;i<=n;i++)
        {
            g[i].clear();
            rg[i].clear();
        }
    }
    return 0;
}
