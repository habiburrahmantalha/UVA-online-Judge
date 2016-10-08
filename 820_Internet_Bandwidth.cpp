#include<stdio.h>
#include<queue>
#include<string.h>
#include<vector>
using namespace std;

int g[110][110],n,m,s,e,mx,mn,visit[110],pi[110];
vector<int>glist[101];
bool bfs(int start,int end)
{
    queue<int>q;
    int i,u,v;
    memset(visit,0,sizeof(visit));
    for(i=0;i<=n;i++)
    pi[i]=i;

    q.push(start);
    visit[start]=1;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<glist[u].size();i++)
        {
            v=glist[u][i];
            if(g[u][v] && visit[v]==0)
            {
                visit[v]=1;
                mn=g[u][v];
                q.push(v);
                pi[v]=u;
                if(v==e)
                return true;

            }
        }
    }


    return false;

}
void minus_path(int x,int y)
{
    if(x==y)
        return;
    else
    {
        //printf("->%d %d\n",x,y);
        g[pi[y]][y]-=mn;
        g[y][pi[y]]-=mn;
        minus_path(x,pi[y]);
    }
}
void min_path(int x,int y)
{
    if(x==y)
        return;
    else
    {
        //printf("->%d %d\n",x,y);
        if(mn>g[pi[y]][y])
        mn=g[pi[y]][y];
        min_path(x,pi[y]);
    }
}
void print()
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)

        printf("%d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int i,a,b,c,t=1;
    while(scanf("%d",&n)==1 && n)
    {
        scanf("%d %d %d",&s,&e,&m);
        memset(g,0,sizeof(g));
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);

            g[a][b]+=c;
            g[b][a]+=c;
            glist[a].push_back(b);
			glist[b].push_back(a);
        }
        mx=0;
        while(bfs(s,e))
        {

            //print();
            //printf("-\n");
            mn=100000000;
            min_path(s,e);
            minus_path(s,e);
            //print();
            mx+=mn;
        }
        printf("Network %d\n",t++);
        printf("The bandwidth is %d.\n\n",mx);

        for(i=1;i<=n;i++)
		glist[i].clear();
    }
    return 0;
}
