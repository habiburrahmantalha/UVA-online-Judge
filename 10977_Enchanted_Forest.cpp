#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
using namespace std;

int g[210][210],R,C;
int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};

bool valid(int x,int y)
{
    if(x<=0 || x>R || y<=0 || y>C)
        return false;
    return true;
}
void bfs()
{
    int u,v,i,x,y;
    queue<int>q;

    if(g[1][1]==-1)
        return;
    g[1][1]=0;
    q.push(1);
    q.push(1);
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(valid(x,y) && g[x][y]==0)
            {
                g[x][y]=g[u][v]+1;
                q.push(x);
                q.push(y);
            }
        }
    }

}
int main()
{
    int i,j,k,a,b,c,m,n,x,y;
    while(scanf("%d %d",&R,&C))
    {
        if(R==0 && C==0)
            break;
        memset(g,0,sizeof(g));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=-1;
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a][b]=1;
            for(j=-c;j<=c;j++)
            {
                for(k=-c;k<=c;k++)
                {
                    x=a+j;
                    y=b+k;
                    if(((a-x)*(a-x)+(b-y)*(b-y))<=c*c)
                        if(valid(x,y))
                        g[x][y]=-1;
                }
            }
        }
        /*
        for(i=1;i<=R;i++)
        {
            for(j=1;j<=C;j++)
                printf("%d",g[i][j]);
            printf("\n");
        }
        */
        bfs();
        if(g[R][C]<=0)
            printf("Impossible.\n");
        else
        printf("%d\n",g[R][C]);
    }
    return 0;
}

