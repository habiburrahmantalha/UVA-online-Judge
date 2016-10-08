#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>

using namespace std;
char g[55][55];
int visit[55][55];
int n,F,E;
int X_4[]={0,-1,0,1};
int Y_4[]={-1,0,1,0};
int X[]={0,-1,-1,-1,0,1,1,1};
int Y[]={-1,-1,0,1,1,1,0,-1};
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;

}

void visit_dfs(int x,int y,char ch)
{
    int i,u,v;
    visit[x][y]=1;
    for(i=0;i<4;i++)
    {
        u=x+X_4[i];
        v=y+Y_4[i];
        if(g[u][v]==ch && visit[u][v]==0)
            visit_dfs(u,v,ch);
    }
}

void bfs(int x,int y)
{
    queue<int>q;
    int u,v,i;

    visit[x][y]=1;
    F=E=0;
    q.push(x);
    q.push(y);

    while(!q.empty())
    {
        u=q.front();q.pop();
        v=q.front();q.pop();
        for(i=0;i<8;i++)
        {
            x=u+X[i];
            y=v+Y[i];
            if(visit[x][y]==0)
            {
                if(g[x][y]=='B')
                {
                    visit_dfs(x,y,'B');
                    F++;
                }
                else if(g[x][y]=='P')
                {
                    visit_dfs(x,y,'P');
                    E++;
                }
                else if(g[x][y]=='*')
                {
                    visit[x][y]=1;
                    q.push(x);
                    q.push(y);
                }
            }

        }
    }

}
int main()
{
    int i,j,S,T;
    while(scanf("%d",&n) && n)
    {
        T=0;
        S=1;
        memset(visit,0,sizeof(visit));

        for(i=0;i<n;i++)
            scanf("%s",g[i]);

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(g[i][j]=='*' && visit[i][j]==0)
                {
                    bfs(i,j);
                    printf("Sector #%d: contain %d freedom fighter group(s) & %d enemy group(s)\n",S++,F,E);
                    if(F && E)
                        T++;
                }
            }
        }
        printf("Total %d group(s) are in fighting position.\n\n",T);
    }
    return 0;
}
