#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
vector<int> G[110];
int g[110][110],visit[110],pi[110],m,n,s,t;
#define in(x) (x*2-1)
#define out(x) (x*2)

bool bfs()
{
    queue<int>q;
    int u,v,i;

    memset(visit,0,sizeof(visit));
    q.push(s);
    visit[s]=1;
    pi[s]=s;

    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            if(visit[v]==0 && g[u][v]>0)
            {
                visit[v]=1;
                pi[v]=u;
                q.push(v);
                if(v==t)
                return true;
            }
        }
    }
    return false;
}
void print()
{
    int i,j;
    for(i=s;i<=t;i++)
    {

        for(j=s;j<=t;j++)
        printf("%5d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int i,a,b,c,mn,u,v;
    long long res;
    while(scanf("%d %d",&n,&m)==2 && n+m)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n-2;i++)
        {
            scanf("%d %d",&a,&c);
            g[in(a)][out(a)]=c;
            G[in(a)].push_back(out(a));
            //printf("%d %d %d %d\n",in(a),out(a),out(a),in(a));
        }
        g[in(1)][out(1)]=(1<<30);
        G[in(1)].push_back(out(1));
        g[in(n)][out(n)]=(1<<30);
        G[in(n)].push_back(out(n));
        s=1;
        t=out(n);


        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[out(a)][in(b)]=g[out(b)][in(a)]=c;
            G[out(a)].push_back(in(b));
            G[out(b)].push_back(in(a));
            //printf("%d %d %d %d\n",in(b),out(a),out(a),in(b));
        }

        //print();
        res=0;
        while(bfs())
        {
            mn=(1<<30);
            for(v=t;v!=s;v=pi[v])
            {
                u=pi[v];
                mn=min(mn,g[u][v]);
            }

            for(v=t;v!=s;v=pi[v])
            {
                u=pi[v];
                //printf("%d %d %d\n",u,v,g[u][v]);
                g[u][v]-=mn;
                g[v][u]+=mn;
                G[v].push_back(u);
            }

            res+=mn;
        }
        printf("%lld\n",res);
        for(i=0;i<=t;i++)
        G[i].clear();
    }
    return 0;
}
