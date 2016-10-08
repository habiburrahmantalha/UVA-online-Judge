#include<stdio.h>
#include<string.h>

bool B,W;
int cnt;
int visit[1001][1001];
char g[1001][1001];

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

bool valid(int x,int y)
{
    if(x<0 || y<0)
    return false;
    return true;
}
void dfs(int u,int v)
{
    int x,y,i;
    cnt++;
    visit[u][v]=1;
    for(i=0;i<4;i++)
    {
        x=u+X[i];
        y=v+Y[i];
        if(valid(x,y))
        {
            if(g[x][y]=='X')
            B=true;
            if(g[x][y]=='O')
            W=true;
            if(g[x][y]=='.' && visit[x][y]==0)
            dfs(x,y);
        }
    }
}
int main()
{
    int tc,i,k,j,black,white;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        black=white=0;
        for(i=0;i<9;i++)
        scanf("%s",g[i]);

        for(j=0;j<9;j++)
        {
            for(k=0;k<9;k++)
            if(g[j][k]=='.' && visit[j][k]==0)
            {
                cnt=0;
                B=W=false;
                dfs(j,k);
                if(B && !W)
                black+=cnt;
                else if(!B && W)
                white+=cnt;
            }
            else if(g[j][k]=='X')
            black++;
            else if(g[j][k]=='O')
            white++;
        }
        printf("Black %d White %d\n",black,white);
    }
    return 0;
}
