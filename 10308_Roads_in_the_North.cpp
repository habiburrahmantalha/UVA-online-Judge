#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

vector<int>g[10010],cost[10010];
int N,visit[10010],d[10010];

void bfs(int s)
{
    queue<int>q;
    int u,v,i,c;

    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));

    visit[s]=1;
    d[s]=0;
    q.push(s);

    while(!q.empty())
    {
        u=q.front();q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            c=cost[u][i];
            if(visit[v]==0)
            {
                visit[v]=1;
                d[v]=d[u]+c;
                q.push(v);
            }
        }
    }
}
void diameter()
{
    int i,dist,x;
    bfs(1);
    dist=0;
    for(i=1;i<=N;i++)
    {
        if(dist<d[i])
        {
            dist=d[i];
            x=i;
        }
    }
    bfs(x);
    dist=0;
    for(i=1;i<=N;i++)
    {
        if(dist<d[i])
        {
            dist=d[i];
            x=i;
        }
    }
    printf("%d\n",dist);

}
int main()
{
    char str[20];
    int a,b,c,i;
    while(gets(str))
    {
        N=0;

        do
        {
            if(strlen(str)==0)
            break;
            sscanf(str,"%d %d %d",&a,&b,&c);

            N=max(N,max(a,b));
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);

        }while(gets(str));
        if(N)
        diameter();
        else
        printf("0\n");
        for(i=0;i<=N;i++)
        {
            g[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
/*
5 1 6
1 4 5
6 3 9
2 6 8
6 1 7
*/
