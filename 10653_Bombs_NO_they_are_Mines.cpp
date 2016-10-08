#include<stdio.h>
#include<queue>>
#include<string.h>
using namespace std;

int g[1010][1010],visit[1010][1010],d[1010][1010];
int row,clmn;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};
bool valid(int x,int y)
{
    if(x<row && x>=0 && y<clmn && y>=0)
        return true;;
    return false;
}
void bfs(int x,int y,int ex,int ey)
{
    int i,u,v;
    if(x==ex && y==ey)
        return;

    queue<int> q;

    d[x][y]=0;
    visit[x][y]=1;

    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];

            if(valid(x,y) && g[x][y]==0 && visit[x][y]==0)
            {
                d[x][y]=d[u][v]+1;
                visit[x][y]=1;
                q.push(x);
                q.push(y);
                if(x==ex && y==ey)
                    return;
            }
        }
    }

}

int main()
{
    int n,i,j,bomb,r,c,sx,sy,ex,ey;
    while(scanf("%d %d",&row,&clmn) )
    {
        if(row==0 && clmn==0)
            break;

       memset(g,0,sizeof(g));
       memset(d,0,sizeof(d));
       memset(visit,0,sizeof(visit));

        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&r);
            scanf("%d",&bomb);
            for(j=0;j<bomb;j++)
            {
                scanf("%d",&c);
                g[r][c]=1;
            }
        }
        scanf("%d %d",&sx,&sy);
        scanf("%d %d",&ex,&ey);
        bfs(sx,sy,ex,ey);
        printf("%d\n",d[ex][ey]);
    }
    return 0;
}
