#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
int X[]={0,-1,0,1,0};
int Y[]={-1,0,1,0,0};
char g[25][25];
int m,n,visit[25][25];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

int bfs(char ch,int x,int y)
{
    queue<int> q;
    int u,v,i,c=1;
    visit[x][y]=1;
    q.push(x);
    q.push(y);
    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<5;i++)
        {
            if(i==4 && (v==0 || v==m-1))
            {
                if(v==0)
                {
                    x=u;
                    y=m-1;
                }
                else
                {
                    x=u;
                    y=0;
                }

            }
            else{
            x=u+X[i];
            y=v+Y[i];
            }
            if(valid(x,y) && visit[x][y]==0 && g[x][y]==ch)
            {

                c++;
                visit[x][y]=1;
                q.push(x);
                q.push(y);
            }
        }
    }
    return c;

}
int main()
{
    int i,j,c,x,y,max;
    while(scanf("%d %d",&n,&m)==2)
    {
        c=0;
        memset(visit,0,sizeof(visit));

        for(i=0;i<n;i++)
            scanf("%s",g[i]);
        scanf("%d %d",&x,&y);
        c=bfs(g[x][y],x,y);

        max=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
            {
                if(visit[i][j]==0 && g[i][j]==g[x][y])
                {

                    c=bfs(g[i][j],i,j);
                    if(max<c)
                        max=c;
                }
            }
        printf("%d\n",max);

    }
    return 0;
}
