#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int R,C,ex,ey;
int visit[110][110],d[110][110];
char g[110][110];
int X[]={-1,-2,-2,-1,1,2,2,1};
int Y[]={-2,-1,1,2,2,1,-1,-2};
int Kx[]={0,-1,-1,-1,0,1,1,1};
int Ky[]={-1,-1,0,1,1,1,0,-1};
bool valid(int x,int y)
{
    if(x<0 || x>=R || y<0 || y>=C)
        return false;
    return true;
}

void knight_attack(int x,int y)
{
    int i,u,v;
    visit[x][y]=1;
    for(i=0;i<8;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && g[u][v]=='.')
                visit[u][v]=1;

    }
}
void bfs(int x,int y)
{
    int i,u,v;
    queue<int> q;
    memset(d,0,sizeof(d));
    d[x][y]=0;
    visit[x][y]=1;
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<8;i++)
        {
            x=u+Kx[i];
            y=v+Ky[i];
            if(valid(x,y) && g[x][y]=='.' && visit[x][y]==0)
            {
                d[x][y]=d[u][v]+1;
                visit[x][y]=1;
                q.push(x);
                q.push(y);
                if(x==ex && y==ey)
                    break;
            }
        }
    }
}
int main()
{
    int tc,i,j,k,x,y;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(visit,0,sizeof(visit));

        scanf("%d %d",&R,&C);

        for(i=0;i<R;i++)
            scanf("%s",g[i]);


        for(i=0;i<R;i++)
            for(j=0;j<C;j++)
            {
                if(g[i][j]=='Z')
                    knight_attack(i,j);
                if(g[i][j]=='A')
                {
                    x=i;
                    y=j;
                }
                if(g[i][j]=='B')
                {
                    ex=i;
                    ey=j;
                }
            }



        g[ex][ey]='.';
        bfs(x,y);
        /*
        for(i=0;i<R;i++)
        {
            for(j=0;j<C;j++)
                printf("%d",visit[i][j]);
            printf("\n");
        }
        */
        if(visit[ex][ey]==0)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",d[ex][ey]);

    }
    return 0;
}
