//connected component
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define PI 2 * acos (0.0)

int visit[50010],N,new_node[50010],old_node[50010],circle_size[50010],size[50010];
vector<int>g[50010],gr[50010],g_new[50010],ts;
stack<int>st;

void dfsf(int u)
{
    visit[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(visit[v]==0)
            dfsf(v);
    }
    st.push(u);
}
void dfsr(int u,int x)
{
    visit[u]=0;
    new_node[u]=x;
    circle_size[x]++;
    old_node[x]=min(u,old_node[x]);
    for(int i=0;i<gr[u].size();i++)
    {
        int v=gr[u][i];
        if(visit[v])
            dfsr(v,x);
    }
}
int g_new_top_sort(int u)
{
    visit[u]=1;
    for(int i=0;i<g_new[u].size();i++)
    {
        int v=g_new[u][i];
        if(visit[v]==0)
            g_new_top_sort(v);
    }
    ts.push_back(u);
}
int main()
{
    int i,j,group,a,b,tc,t=1,mx,mxi;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&N);
        for(i=0;i<N;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            gr[b].push_back(a);
        }
        memset(visit,0,sizeof(visit));
        for(i=1;i<=N;i++)
            if(visit[i]==0)
                dfsf(i);

        group=0;
        memset(old_node,63,sizeof(old_node));
        memset(circle_size,0,sizeof(circle_size));
        while(!st.empty())
        {
            i=st.top();st.pop();
            if(visit[i])
                dfsr(i,++group);
        }
        for(i=1;i<=N;i++)
        {
            for(j=0;j<g[i].size();j++)
            {
                if(new_node[i]!=new_node[g[i][j]])
                g_new[new_node[i]].push_back(new_node[g[i][j]]);
            }
        }

        for(i=1;i<=group;i++)
            if(visit[i]==0)
                g_new_top_sort(i);

        memset(size,0,sizeof(size));

        for(i=0;i<ts.size();i++)
        {
            size[ts[i]]=circle_size[ts[i]];
            for(j=0;j<g_new[ts[i]].size();j++)
            size[ts[i]]+=size[g_new[ts[i]][j]];
        }
        mx=0;
        mxi=50010;
        for(i=1;i<=group;i++)
        {
            //printf("%d %d %d\n",i,old_node[i],size[i]);
            if(size[i]>mx)
            {
                mx=size[i];
                mxi=old_node[i];
            }
            else if(size[i]==mx)
            {

                if(mxi>old_node[i])
                mxi=old_node[i];

            }
        }
        printf("Case %d: %d\n",t++,mxi);
        for(i=0;i<=N;i++)
        {
            g[i].clear();
            gr[i].clear();
            g_new[i].clear();
        }
        ts.clear();

    }
    return 0;
}
