#include<stdio.h>
#include<string.h>

int visit[30][30],n,m,cnt;
char g[30][30];
int X[]={0,1,1,1,0,-1,-1,-1};
int Y[]={1,1,0,-1,-1,-1,0,1};
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    return true;
}

void visit_dfs(int x,int y)
{
    int i,a,b;
    for(i=0;i<8;i++)
    {
        a=x+X[i];
        b=y+Y[i];
        if(valid(a,b) && g[a][b]=='1' && visit[a][b]==0)
        {
            visit[a][b]=1;
            cnt++;
            visit_dfs(a,b);
        }
    }
}

int dfs()
{
    int i,j,mx;
    cnt=0;
    memset(visit,0,sizeof(visit));
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(g[i][j]=='1' && visit[i][j]==0)
            {
                visit[i][j]=1;
                cnt=1;
                visit_dfs(i,j);
            }
            mx=(mx<cnt)?cnt:mx;
        }
    }
    return mx;
}


int main()
{
    //freopen("in.txt","r",stdin);
    int T;
    bool f=false;
    scanf("%d",&T);
    getchar();
    getchar();
    while(T--)
    {
        if(f)
            printf("\n");
        n=0;
        memset(g,0,sizeof(g));
        while(scanf("%[0-9]",g[n]))
        {
            getchar();
            if(g[n][0]==0)
                break;
            n++;
        }
        m=strlen(g[0]);
        getchar();
        printf("%d\n",dfs());
        f=true;
    }
    return 0;
}
