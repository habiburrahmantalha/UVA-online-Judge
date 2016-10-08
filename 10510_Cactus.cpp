//Problem Type :    Strongly connected component,cactus properties//10510 - cactus
//Time :    0.028
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#include<stack>
using namespace std;
#define PI 2 * acos (0.0)

vector<int>G[10010],Gr[10010];
bool V[10010],cactus;
int Visit[10010],n;

bool visitall()
{
    for(int i=0;i<n;i++)
    if(!V[i])
        return false;
    return true;
}

void DFS(int u)
{
    V[u]=true;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!V[v])
            DFS(v);
    }

}
void DFSr(int u)
{
    V[u]=true;
    for(int i=0;i<Gr[u].size();i++)
    {
        int v=Gr[u][i];
        if(!V[v])
            DFSr(v);
    }
}
void forward_edge(int u)
{
    Visit[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];

        if(!Visit[v])
            forward_edge(v);
        else if(Visit[v]==2)
            cactus=false;
    }
    Visit[u]=2;

}
int main()
{
    int tc,a,b,i,m;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            G[a].push_back(b);
            Gr[b].push_back(a);
        }

        memset(V,false,sizeof(V));
        DFS(0);
        if(!visitall())
        {
            printf("NO\n");
            continue;
        }
        memset(V,false,sizeof(V));
        DFSr(0);
        if(!visitall())
        {
            printf("NO\n");
            continue;
        }

        cactus=true;
        memset(Visit,0,sizeof(Visit));
        forward_edge(0);

        if(cactus)
            printf("YES\n");
        else
            printf("NO\n");

        for(i=0;i<=n;i++)
        {
            G[i].clear();
            Gr[i].clear();
        }
    }
    return 0;
}
