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

int X[]={-1,-3,-3,-1,1,3,3,1};
int Y[]={-3,-1,1,3,3,1,-1,-3};
int n,m,sr,sc,dr,dc;
bool visit[20][20],visit2[20][20];
int d[20][20],d2[20][20];
bool valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
    return false;
    return true;
}
bool prime(int x)
{
    if(x==2 ||x==3 || x==5 || x==7)
    return true;

    return false;
}
void bfs()
{
    int x,y,u,v,i;
    queue<int>q;

    memset(visit,false,sizeof(visit));
    memset(d,0,sizeof(d));

    q.push(sr);
    q.push(sc);
    visit[sr][sc]=true;
    d[sr][sc]=0;

    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();

        for(i=0;i<8;i++)
        {
            u=x+X[i];
            v=y+Y[i];

            if(valid(u,v) && !visit[u][v])
            {

                q.push(u);
                q.push(v);
                visit[u][v]=true;
                d[u][v]=d[x][y]+1;

                //if(u==dr && v==dc)
                //return;
            }
        }
    }
}

void bfs2()
{
    int x,y,u,v,i;
    queue<int>q;

    memset(visit2,false,sizeof(visit2));
    memset(d2,0,sizeof(d2));

    q.push(sr);
    q.push(sc);

    d2[sr][sc]=0;
    visit2[sr][sc]=true;

    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();

        for(i=0;i<8;i++)
        {
            u=x+X[i];
            v=y+Y[i];

            if(valid(u,v) && !visit2[u][v])
            {

                q.push(u);
                q.push(v);
                d2[u][v]=d2[x][y]+1;
                if(prime(d2[u][v]))
                visit2[u][v]=true;
            }
        }
    }
}

int main()
{
    int t=1;
    while(scanf("%d %d %d %d %d %d",&n,&m,&sr,&sc,&dr,&dc)==6)
    {

        bfs();
        bfs2();
        if(!visit[dr][dc] && !visit2[dr][dc])
            printf("CASE# %d: Destination is not reachable.\n",t++);
        else if(prime(d2[dr][dc]))
            printf("CASE# %d: The knight takes %d prime moves.\n",t++,d2[dr][dc]);
        else
            printf("CASE# %d: The knight takes %d composite move(s).\n",t++,d[dr][dc]);
/*
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                printf("%d ",d[i][j]);
            printf("\n");
        }
        */
    }
    return 0;
}
