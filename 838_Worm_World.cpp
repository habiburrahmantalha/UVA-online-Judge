#include<stdio.h>
#include<queue>
#include<string.h>

using namespace std;

int X[]={1,0,-1,0};
int Y[]={0,1,0,-1};

int n,g[13][13],number[1010],visit[13][13],mx,r[13][13];

bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=n)
        return false;
    return true;
}
void dfs(int x,int y,int k)
{
    if(r[x][y]<k)
    r[x][y]=k;
    else
    return;

    bool f=false;
    int i,u,v;
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && visit[u][v]==0 && number[g[u][v]]==0)
        {
            f=true;
            visit[u][v]=1;
            number[g[u][v]]=1;
            dfs(u,v,k+1);
            visit[u][v]=0;
            number[g[u][v]]=0;
        }
    }
    if(!f)
    {
        if(mx<k)
        mx=k;
    }

}

int main()
{
    int tc,i,j;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");
        f=true;

        memset(g,0,sizeof(g));

        memset(number,0,sizeof(number));
        memset(visit,0,sizeof(visit));
        mx=0;
        scanf("%d",&n);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&g[i][j]);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                memset(r,0,sizeof(r));
                number[g[i][j]]=1;
                visit[i][j]=1;
                dfs(i,j,1);
                visit[i][j]=0;
                number[g[i][j]]=0;
            }
        printf("%d\n",mx);


    }
    return 0;
}
