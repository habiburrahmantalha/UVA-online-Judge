#include<stdio.h>
#include<string.h>

int g[110][110],visit[110],visit2[110],n;
char D[110][110];

void dfs(int u)
{
    visit[u]=1;
    for(int i=0;i<n;i++)
    if(g[u][i] && visit[i]==0)
    dfs(i);
}
void dfs2(int u)
{

    visit2[u]=1;
    for(int i=0;i<n;i++)
    if(g[u][i] && visit2[i]==0)
    dfs2(i);
}
int main()
{
    int tc,i,j,k,t=1;
    scanf("%d",&tc);

    while(tc--)
    {

        scanf("%d",&n);

        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&g[i][j]);

        memset(D,'N',sizeof(D));

        memset(visit,0,sizeof(visit));
            dfs(0);

        for(i=0;i<n;i++)
        {

            memset(visit2,0,sizeof(visit2));
            visit2[i]=1;
            if(i!=0)
            dfs2(0);

            if(visit[i])
            D[i][i]='Y';
            for(k=0;k<n;k++)
            if(visit[k]==1 && visit2[k]==0)
            D[i][k]='Y';


        }
        printf("Case %d:\n",t++);
        for(i=0;i<n;i++)
        {
            printf("+");
            for(j=1;j<n*2;j++)
            printf("-");
            printf("+\n");

            printf("|");
            for(j=0;j<n;j++)
            printf("%c|",D[i][j]);
            printf("\n");
        }
        printf("+");
        for(j=1;j<n*2;j++)
        printf("-");
        printf("+\n");
    }
    return 0;
}
