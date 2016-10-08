#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int N,M,xs,xe,ys,ye;
char g[30][30];
int d[30][30][10][10],visit[30][30][10][10];
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
        //W,N,E,S

bool valid(int x,int y)
{
    if(x<0 || x>=N || y<0 || y>=M)
    return false;

    return true;
}

int bfs()
{
    int u,v,w,c,cn,x,y,z,i;
    queue<int>q;

    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));

    visit[xs][ys][1][0]=1;
    d[xs][ys][1][0]=0;
    q.push(xs);
    q.push(ys);
    q.push(1);
    q.push(0);

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        w=q.front();q.pop();
        c=q.front();q.pop();

        //left
        z=(w+3)%4;
        if(visit[u][v][z][c]==0)
        {
            visit[u][v][z][c]=1;
            d[u][v][z][c]=d[u][v][w][c]+1;
            q.push(u);
            q.push(v);
            q.push(z);
            q.push(c);
            if(visit[xe][ye][z][0])
            return d[xe][ye][z][0];
        }

        //right
        z=(w+1)%4;
        if(visit[u][v][z][c]==0)
        {
            visit[u][v][z][c]=1;
            d[u][v][z][c]=d[u][v][w][c]+1;
            q.push(u);
            q.push(v);
            q.push(z);
            q.push(c);
            if(visit[xe][ye][z][0])
            return d[xe][ye][z][0];
        }

        //forward
        x=u+X[w];
        y=v+Y[w];
        cn=(c+1)%5;
        if(valid(x,y) && visit[x][y][w][cn]==0 && g[x][y]=='.')
        {
            visit[x][y][w][cn]=1;
            d[x][y][w][cn]=d[u][v][w][c]+1;
            q.push(x);
            q.push(y);
            q.push(w);
            q.push(cn);
            if(visit[xe][ye][w][0])
            return d[xe][ye][w][0];
        }
    }
    return -1;
}
void get_S_D()
{
    int i,j;
    for(i=0;i<N;i++)
    for(j=0;j<M;j++)
    {
        if(g[i][j]=='S')
        {
            xs=i;
            ys=j;
            g[i][j]='.';
        }
        if(g[i][j]=='T')
        {
            xe=i;
            ye=j;
            g[i][j]='.';
        }
    }
}
int main()
{
    int i,time,t=1;
    bool NL=false;

    while(scanf("%d %d",&N,&M) && N+M)
    {
        for(i=0;i<N;i++)
        scanf("%s",g[i]);

        get_S_D();

        time = bfs();

        if(NL)
        printf("\n");
        NL=true;
        printf("Case #%d\n",t++);
        if(time==-1)
        printf("destination not reachable\n");
        else
        printf("minimum time = %d sec\n",time);
    }
    return 0;
}
