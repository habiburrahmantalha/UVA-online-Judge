#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

char g[1001][1001];
int n,m,visit[1001][1001],res[1001][1001];
int X[]={0,1,1,1,0,-1,-1,-1};
int Y[]={2,2,0,-2,-2,-2,0,2};

bool valid(int x,int y)
{
    if(x<0 || y<0 || x>=n || y>=m)
        return false;
    return true;
}
void bfs(int x,int y,int f,char ch)
{
    int a,b,i;
    queue <int> q;
    visit[x][y]=1;

    g[x][y]=f+'0';
    q.push(x);
    q.push(y);

    while(!q.empty())
    {
        a=q.front();
        q.pop();
        b=q.front();
        q.pop();
        for(i=0;i<8;i++)
        {
            x=a+X[i];
            y=b+Y[i];
            if(valid(x,y) && g[x][y]==ch && visit[x][y]==0)
            {

                visit[x][y]=1;
                res[x][y]=f;
                q.push(x);
                q.push(y);
            }
        }
    }
}

int main()
{
    int i,j,f=1;
    n=0;

    while(1)
    {
        gets(g[n]);
        if(g[n][0]=='%')
        {
            memset(visit,0,sizeof(visit));
            memset(res,0,sizeof(res));
            m=strlen(g[0]);
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j+=2)
                {
                    if(visit[i][j]==0)
                    {
                        bfs(i,j,f,g[i][j]);
                        f++;
                    }
                }
            }
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j+=2)
                    printf("%2d",res[i][j]);
            }

            memset(g,0,sizeof(g));
            memset(visit,0,sizeof(visit));
            n=0;
            f=1;

        }
        n++;


    }
    return 0;
}
