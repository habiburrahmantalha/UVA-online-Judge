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

bool g[2010][2010];
bool visit[2010];
vector<int> ts;
int n,x[2010],y[2010],d[2010];

void make_graph()
{
    int i,j,r;
    memset(g,false,sizeof(g));
    for(i=0;i<n;i++)
    {
        r=d[i]/2;
        for(j=0;j<n;j++)
        {
            if(abs(x[i]-x[j])<=r && abs(y[i]-y[j])<=r && i!=j)
            g[i][j]=true;
        }
    }
}
void top_sort(int u)
{
    int v;
    visit[u]=true;
    for(v=0;v<n;v++)
        if(!visit[v] && g[u][v])
            top_sort(v);
    ts.push_back(u);
}
void dfs(int u)
{
    int v;
    visit[u]=false;
    for(v=0;v<n;v++)
        if(visit[v] && g[u][v])
            dfs(v);
}
int main()
{
    int tc,i,j,mine;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d %d",&x[i],&y[i],&d[i]);

        make_graph();

        ts.clear();
        memset(visit,false,sizeof(visit));
        for(i=0;i<n;i++)
            if(!visit[i])
                top_sort(i);

        mine=0;
        for(i=ts.size()-1;i>=0;i--)
        {
            if(visit[ts[i]])
            {
                mine++;
                dfs(ts[i]);
            }
        }

        printf("%d\n",mine);
    }
    return 0;
}
