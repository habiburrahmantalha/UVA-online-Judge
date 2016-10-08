//Problem Type : BFS
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

int X[]={0,0,1};
int Y[]={-1,1,0};
int d[80][80][7],visit[80][80][7];
int N,K,g[80][80];
bool valid(int x,int y)
{
    if(x<0 || y< 0 || x>=N || y>=N)
    return false;
    return true;
}
void bfs()
{
    queue<int> q;
    memset(d,0,sizeof(d));
    memset(visit,0,sizeof(visit));
    int x,y,k,i,u,v;

    q.push(0);
    q.push(0);
    q.push(K);
    d[0][0][K]=g[0][0];
    visit[0][0][K]=1;

    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();
        k=q.front();q.pop();

        for(i=0;i<3;i++)
        {
            u=x+X[i];
            v=y+Y[i];

            if(!valid(u,v))
            continue;

            if(g[u][v]<0)
            {
                if(d[u][v][k-1]<d[x][y][k]+g[u][v] && (k-1)>=0)
                {
                    d[u][v][k-1]=d[x][y][k]+g[u][v];
                    visit[u][v][k-1]=1;
                    q.push(u);
                    q.push(v);
                    q.push(k-1);

                }

            }
            else
            {
                if(d[u][v][k]<d[x][y][k]+g[u][v])
                {

                    d[u][v][k]=d[x][y][k]+g[u][v];
                    visit[u][v][k]=1;
                    q.push(u);
                    q.push(v);
                    q.push(k);

                }
            }

        }
    }

}
void print()
{
    int i,j,k;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d %d : ",i,j);
            for(k=0;k<=K;k++)
                printf("%d ",d[i][j][k]);
            printf("\n");
        }
    }
}
int main()
{
    int i,j;
    int t=1,mx;
    while(scanf("%d %d",&N,&K) && N+K)
    {
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                scanf("%d",&g[i][j]);
        bfs();
        print();
        mx=0;
        for(i=0;i<=K;i++)
        mx=max(mx,d[N-1][N-1][i]);

        if(mx==0)
        printf("Case %d: impossible\n",t++);
        else
        printf("Case %d: %d\n",t++,mx);

    }
    return 0;
}
