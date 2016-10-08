#include<stdio.h>//power transmission
#include<queue>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
vector<int>G[210];
int g[210][210],visit[210],pi[210],n;
#define in(x) (x*2-1)
#define out(x) (x*2)

bool bfs()
{
    queue<int>q;
    int u,v,i;

    memset(visit,0,sizeof(visit));

    q.push(0);

    visit[0]=1;
    pi[0]=0;

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<G[u].size();i++)
        {
            v=G[u][i];
            if(visit[v]==0 && g[u][v]>0)
            {
                //printf("%d %d*\n",u,v);
                visit[v]=1;
                pi[v]=u;
                q.push(v);
                if(v==2*n+1)
                return true;
            }
        }
    }
    return false;
}
void print()
{
    int i,j;
    for(i=0;i<=2*n+1;i++)
    {
        for(j=0;j<=2*n+1;j++)
        printf("%d ",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int i,j,a,b,c,x,m,mn,u,v,s,t,res;
    while(scanf("%d",&n)==1)
    {
        memset(g,0,sizeof(g));


        for(i=1;i<=n;i++)
        {
            scanf("%d",&x);
            g[in(i)][out(i)]=x;
            G[in(i)].push_back(out(i));
        }

        //print();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[out(a)][in(b)]=c;
            G[out(a)].push_back(in(b));
        }
        scanf("%d %d",&s,&t);
        for(i=0;i<s;i++)
        {
            scanf("%d",&x);
            g[0][in(x)]=(1<<30);
            G[0].push_back(in(x));
        }
        for(i=0;i<t;i++)
        {
            scanf("%d",&x);
            //C[x]=(1<<30);
            g[out(x)][2*n+1]=(1<<30);
            G[out(x)].push_back(2*n+1);
        }
        //print();
        res=0;
        while(bfs())
        {
            mn=(1<<30);
            for(v=2*n+1;v!=0;v=pi[v])
            {
                u=pi[v];
                mn=min(mn,g[u][v]);
            }

            for(v=2*n+1;v!=0;v=pi[v])
            {
                u=pi[v];
                //printf("%d %d\n",u,v);
                g[u][v]-=mn;
                g[v][u]+=mn;
                G[v].push_back(u);

            }

            res+=mn;
            //printf("%d\n",mn);
        }

        printf("%d\n",res);
        for(i=0;i<=2*n+1;i++)
        G[i].clear();
    }
    return 0;
}


