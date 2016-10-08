#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;
int g[8][8][5],ex,ey,sx,sy;
int visit[8][8],pi[8][8];

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
char direction[]={"NESW"};
bool valid(int x,int y)
{
    if(x<0 || x>=6 || y<0 || y>=6)
        return false;
    return true;
}
void create_wall()
{
    int a,b,c,d,x,y,i,x1,x2,y1,y2;

    for(i=0;i<3;i++)
    {
        scanf("%d %d %d %d",&b,&a,&d,&c);
        if(a==c)
        {

            x1=a;
            x2=a-1;
            if(b>d)
                swap(b,d);
            for(y=b;y<d;y++)
            {
                //printf("%d %d\n",x1,y);
                g[x1][y][0]=1;
                if(valid(x2,y))
                {
                    //printf("%d %d\n",x2,y);
                    g[x2][y][2]=1;
                }

            }

        }
        else
        {
            y1=b;
            y2=b-1;
            if(a>c)
                swap(a,c);
            for(x=a;x<c;x++)
            {
                //printf("%d %d\n",x,y1);
                g[x][y1][3]=1;

                if(valid(x,y2))
                {
                    //printf("%d %d\n",x,y2);
                    g[x][y2][1]=1;
                }

            }
        }
    }
}
int dir(int d)
{
    if(d==0)
        return 2;
    if(d==1)
        return 3;
    if(d==2)
        return 0;
    if(d==3)
        return 1;
}

void print_path(int x,int y,int i)
{
    if(x==sx && y==sy)
    {
        //printf("%d",i);
        return;
    }
    x=x+X[dir(i)];
    y=y+Y[dir(i)];
    print_path(x,y,pi[x][y]);
    printf("%c",direction[i]);
}

void bfs(int x,int y)
{
    int u,v,i,j;
    queue<int>q;
    memset(visit,0,sizeof(visit));
    q.push(x);
    q.push(y);

    visit[x][y]=1;
    memset(pi,-1,sizeof(pi));

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            j=dir(i);
            if(valid(x,y) && g[u][v][i]!=1 && visit[x][y]==0)
            {
                //printf("%d %d\n",x,y);
                visit[x][y]=1;
                pi[x][y]=i;
                if(x==ex && y==ey)
                {
                    print_path(x,y,i);
                    printf("\n");
                    return;
                }
                q.push(x);
                q.push(y);
            }
        }
    }
}

int main()
{
    while(scanf("%d %d",&sy,&sx))
    {
        if(sx==0 && sy==0)
            break;
        sx--;sy--;

        scanf("%d %d",&ey,&ex);
        ex--;ey--;
        memset(g,0,sizeof(g));
        create_wall();
        bfs(sx,sy);

    }
    return 0;
}
