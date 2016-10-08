#include<stdio.h>
#include<string.h>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;

int fa[100001],fb[100001],visit[100001];
vector<int>g[100001];
bool bfs(int s)
{
    queue<int>q;
    int i,u,v;
    memset(visit,0,sizeof(visit));
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=0;v<g[u].size();v++)
        {
            if(g[u][v] && visit[g[u][v]]==0)
            {
                visit[g[u][v]]=1;
                q.push(g[u][v]);
            }
        }
    }
    for(i=0;i<10001;i++)
        if(fa[i] || fb[i])
        if(visit[i]==0)
            return false;
    return true;

}
int root()
{
    int i,r=0;
    for(i=1;i<100001;i++)
    {
        if(fa[i]>0)
        {
            if(fb[i]==0)
            {
                if(r>0)
                    return 0;
                r=i;
            }
        }
    }
    return r;
}

int main()
{
    int a,b,s,t=1,i;
    bool tree;
    while(scanf("%d %d",&a,&b))
    {
        for(i=0;i<100001;i++)
            g[i].clear();
        memset(fa,0,sizeof(fa));
        memset(fb,0,sizeof(fb));
        tree=true;
        if(a<0 && b<0)
            break;
        do
        {
            if(a==0 && b==0)
                break;
            if(tree)
            {
                g[a].push_back(b);
                fa[a]++;
                fb[b]++;

                if(fb[b]>1)
                tree=false;
            }
        }while(scanf("%d %d",&a,&b));


        if(tree)
        s=root();

        if(s==-1)
            tree=false;

        if(tree && bfs(s))
            printf("Case %d is a tree.\n",t++);
        else
            printf("Case %d is not a tree.\n",t++);

    }
    return 0;
}
