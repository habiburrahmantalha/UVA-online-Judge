#include<stdio.h>
#include<string.h>
#include<queue>

using namespace std;

int r,c,xs,xe,ys,ye;
char g[300+5][300+5];
int visit[300+5][300+5][5];

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};


bool valid(int x,int y)
{
    if(x>=r || x<0 || y<0 || y>=c)
        return false;
    return true;
}
bool wall(int x,int y,int i,int j)
{
    int k;
    for(k=1;k<=j;k++)
    {
        x+=X[i];
        y+=Y[i];
        if(g[x][y]=='#')
        return true;
    }
    return false;
}
int bfs()
{
    memset(visit,0,sizeof(visit));
    int i,xv,xu,yv,yu,dist,mov;
    queue<int>q,p;

    q.push(xs);
    q.push(ys);

    visit[xs][ys][1]=1;
    p.push(0);

    while(!q.empty())
    {
        xu=q.front();q.pop();
        yu=q.front();q.pop();

        dist=p.front();p.pop();

        mov=dist%3+1;

        for(i=0;i<4;i++)
        {
            xv=xu+X[i]*mov;
            yv=yu+Y[i]*mov;
            if(valid(xv,yv) && visit[xv][yv][mov]==0 && !wall(xu,yu,i,mov))
            {
                visit[xv][yv][mov]=1;
                q.push(xv);
                q.push(yv);
                p.push(dist+1);
                if(xv==xe && yv==ye)
                return dist+1;
            }
        }
    }
    return -1;
}
int main()
{
    int tc,i,j,res;

    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d",&r,&c);
        for(i=0;i<r;i++)
            scanf("%s",&g[i]);

        bool start=false,end=false;

        for(i=0;i<r;i++)
        {
            if(start && end)
                break;
            for(j=0;j<c;j++)
            {
                if(start && end)
                    break;
                if(g[i][j]=='S')
                {
                    xs=i;
                    ys=j;
                    start=true;

                }
                if(g[i][j]=='E')
                {
                    xe=i;
                    ye=j;
                    g[i][j]='.';
                    end=true;

                }
            }
        }
        res=bfs();
        if(res==-1)
            printf("NO\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
