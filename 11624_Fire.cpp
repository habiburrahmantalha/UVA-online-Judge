#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char g[1010][1010];
int d_fire[1010][1010],d_joe[1010][1010];
int R,C;
int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

bool valid(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}
void bfs_fire(int x,int y)
{
    queue<int>q;
    int u,v,i;
    memset(d_fire,-1,sizeof(d_fire));
    q.push(x);
    q.push(y);
    d_fire[x][y]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && g[x][y]=='.' && d_fire[x][y]==-1)
            {
                d_fire[x][y]=d_fire[u][v]+1;
                q.push(x);
                q.push(y);
            }

        }
    }
}

void bfs_joe(int x,int y)
{
    queue<int>q;
    int u,v,i;
    memset(d_joe,-1,sizeof(d_joe));
    q.push(x);
    q.push(y);
    d_joe[x][y]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(!valid(x,y))
            {
                printf("%d\n",d_joe[u][v]+1);
                return ;
            }
            if(g[x][y]=='.' && d_joe[x][y]==-1 && d_fire[x][y]>d_joe[u][v]+1)
            {
                d_joe[x][y]=d_joe[u][v]+1;
                q.push(x);
                q.push(y);
            }

        }
    }
    printf("IMPOSSIBLE\n");
}

int main()
{
    int tc,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&R,&C);
        for(i=0;i<R;i++)
            scanf("%s",g[i]);
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            if(g[i][j]=='F')
            {
                bfs_fire(i,j);
                i=R;
                break;
            }
        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            if(g[i][j]=='J')
            {
                bfs_joe(i,j);
                i=R;
                break;
            }
    }
    return 0;
}
