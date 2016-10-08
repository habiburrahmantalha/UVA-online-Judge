#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

int m,visit[30],r[30],canvisit[30],c,n;
vector<int>g[50];

void dfs(int u)
{
    canvisit[u]=1;
    visit[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(visit[v]==0)
            dfs(v);
    }
}

void routs(int u,int k)
{
    int i;
    visit[u]=1;
    r[k]=u;
    if(u==m)
    {
        for(i=0;i<k;i++)
            printf("%d ",r[i]);
        printf("%d\n",r[i]);
        c++;
        return;
    }
    for(i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(canvisit[v] && visit[v]==0)
        {
            visit[v]=1;
            routs(v,k+1);
            visit[v]=0;
        }
    }
}
void sort_graph()
{
    for(int i=1;i<=n;i++)
    sort(g[i].begin(),g[i].end());
}
int main()
{
    int a,b,t=1,i;

    while(scanf("%d",&m)==1)
    {

        while(scanf("%d %d",&a,&b) && a && b)
        {
            n=max(n,max(a,b));
            g[a].push_back(b);
            g[b].push_back(a);
        }
        sort_graph();
        memset(canvisit,0,sizeof(canvisit));
        memset(visit,0,sizeof(visit));
        dfs(m);
        c=0;
        memset(visit,0,sizeof(visit));
        printf("CASE %d:\n",t++);
        routs(1,0);
        printf("There are %d routes from the firestation to streetcorner %d.\n",c,m);

        for(i=0;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
