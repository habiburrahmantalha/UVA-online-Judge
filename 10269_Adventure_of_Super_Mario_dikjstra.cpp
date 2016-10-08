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

//int g[105][105];
int dist[105][505][15];
vector<int>g[105],cost[105];
int N,A,B,L,K,inf;
void bfs()
{
    queue<int>q;
    int u,v,c,d,dd,k,kk,i;
    memset(dist,0x7F,sizeof(dist));
    inf=dist[0][0][0];
    N=A+B;
    dist[N][0][K]=0;
    q.push(N);
    q.push(0);
    q.push(K);

    while(!q.empty())
    {
        u=q.front();q.pop();
        d=q.front();q.pop();
        k=q.front();q.pop();

        //for(v=1;v<=N;v++)
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            //if(g[u][v])
            {

                c=cost[u][i];
                //village
                if(v<=A)
                {

                    //option 1:still have some magic boot run
                    if(d>=c)
                    {
                        dd=d-c;
                        if(dist[v][dd][k]>dist[u][d][k])
                        {
                            dist[v][dd][k]=dist[u][d][k];
                            q.push(v);
                            q.push(dd);
                            q.push(k);
                        }

                    }

                    //option 2: start a magic boot run
                    if(k>0 && L>=c)
                    {
                        dd=L-c;
                        kk=k-1;
                        if(dist[v][dd][kk]>dist[u][d][k])
                        {
                            dist[v][dd][kk]=dist[u][d][k];
                            q.push(v);
                            q.push(dd);
                            q.push(kk);
                        }
                    }

                    //option 3:walk with out magic boot
                    if(dist[v][0][k]>dist[u][d][k]+c)
                    {
                        dist[v][0][k]=dist[u][d][k]+c;
                        q.push(v);
                        q.push(0);
                        q.push(k);
                    }

                }
                //castle
                else
                {
                    //option 1:start a magic boot run
                    if(k>0 && L>=c)
                    {
                        //dd=L-c;
                        kk=k-1;
                        if(dist[v][0][kk]>dist[u][d][k])
                        {
                            dist[v][0][kk]=dist[u][d][k];
                            q.push(v);
                            q.push(0);
                            q.push(kk);
                        }
                    }
                    //option 2:walk with out magic boot
                    if(dist[v][0][k]>dist[u][d][k]+c)
                    {

                        dist[v][0][k]=dist[u][d][k]+c;
                        q.push(v);
                        q.push(0);
                        q.push(k);
                    }

                }
            }
        }
    }
}
void min_distance()
{
    int i,j,k,mn;
    mn=inf;
    //for(k=1;k<+N;k++)
    for(i=0;i<=K;i++)
    {
        for(j=0;j<=L;j++)
            //cout<<dist[1][j][i]<<" ";
        //cout<<endl;
            mn=min(mn,dist[1][i][j]);
    }
    printf("%d\n",mn);

}
int main()
{
    int tc,M,i,a,b,c;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(g,0,sizeof(g));
        scanf("%d %d %d %d %d",&A,&B,&M,&L,&K);
        for(i=0;i<M;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            //g[a][b]=g[b][a]=c;
            g[a].push_back(b);
            g[b].push_back(a);
            cost[a].push_back(c);
            cost[b].push_back(c);
        }

        bfs();
        min_distance();

        for(i=0;i<=N;i++)
        {
            g[i].clear();
            cost[i].clear();
        }

    }
    return 0;
}
