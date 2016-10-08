//Problem Type :    Euler Cycle
//Time :
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
using namespace std;
#define PI 2 * acos (0.0)

int D[210],n,m;
bool G[210][210],V[210];

bool even_degree()
{
    for(int i=0;i<n;i++)
    if(D[i]%2!=0)
    return false;

    return true;
}
void dfs(int u)
{
    V[u]=true;
    for(int v=0;v<n;v++)
        if(G[u][v] && !V[v])
            dfs(v);
}
bool connected()
{
    memset(V,false,sizeof(V));
    for(int i=0;i<n;i++)
        if(D[i])
        {
            dfs(i);
            break;
        }

    for(int i=0;i<n;i++)
        if(D[i] && !V[i])
            return false;

    return true;
}
int main()
{
    int i,a,b;
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(G,false,sizeof(G));

        memset(D,0,sizeof(D));
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            G[a][b]=G[b][a]=true;
            D[a]++;
            D[b]++;
        }
        if(!m || !even_degree() || !connected())
            printf("Not Possible\n");
        else
            printf("Possible\n");
    }
    return 0;
}
