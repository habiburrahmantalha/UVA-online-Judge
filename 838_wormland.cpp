#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

int n,g[13][13],number[1010],visit[13][13],d[13][13];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}
int bfs(int x,int y)
{
    queue<int> q;
    int u,v,max=0,i;

    q.push(x);
    q.push(y);

    memset(d,0,sizeof(d));
    memset(visit,0,sizeof(visit));
    memset(number,0,sizeof(number));

    d[x][y]=1;
    visit[x][y]=1;
    number[g[x][y]]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();

        for(i=0;i<4;i++)
        {
            x=u+X[i];
            y=v+Y[i];

            if(valid(x,y) && visit[x][y]==0 && number[g[x][y]]==0)
            {
                d[x][y]=d[u][v]+1;
                visit[x][y]=1;
                number[g[x][y]]=1;
                q.push(x);
                q.push(y);
                if(d[x][y]>max)
                    max=d[x][y];
            }
        }
    }
    return max;
}

int main()
{
    int tc,i,j,count,max;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");

        memset(g,0,sizeof(g));
        max=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                count=bfs(i,j);
                if(count>max)
                    max=count;
            }
        printf("%d\n",max);
        f=true;

    }
    return 0;
}
