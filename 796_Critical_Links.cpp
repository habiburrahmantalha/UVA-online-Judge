//Problem Type :    bridge,critical link
//Time :    .012
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

int dfs_low[110],dfs_num[110],dfs_num_count,n,g[110][110],parent[110];
vector<pair<int,int> > edge;

void bridge(int u)
{
    //cout<<u<<" ";
    dfs_low[u]=dfs_num[u]=dfs_num_count++;
    for(int v=0;v<n;v++)
    {
        //cout<<u<<" * "<<v<<endl;
        if(g[u][v] && dfs_num[v]==-1)
        {
            parent[v]=u;
            bridge(v);
            if(dfs_low[v]>dfs_num[u])
            {
                if(u<v)
                edge.push_back(make_pair(u,v));
                else
                edge.push_back(make_pair(v,u));


            }
            //printf("%d %d\n",u,v);
            dfs_low[u]=min(dfs_low[v],dfs_low[u]);
        }
        else if(g[u][v] && v!=parent[u])
        {
            //cout<<u<<" "<<v<<endl;
            dfs_low[u]=min(dfs_num[v],dfs_low[u]);
        }
    }
}
int main()
{
    int i,a,b,m,j;
    while(scanf("%d",&n)==1)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
        {
            scanf("%d (%d)",&a,&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&b);
                g[a][b]=g[b][a]=1;
            }
        }

        dfs_num_count=0;
        memset(dfs_num,-1,sizeof(dfs_num));
        memset(dfs_low,0,sizeof(dfs_low));

        for(i=0;i<n;i++)
            if(dfs_num[i]==-1)
                bridge(i);

        sort(edge.begin(),edge.end());
        printf("%d critical links\n",edge.size());
        for(i=0;i<edge.size();i++)
            printf("%d - %d\n",edge[i].first,edge[i].second);
        printf("\n");

        edge.clear();
    }
    return 0;
}
