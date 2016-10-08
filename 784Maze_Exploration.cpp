#include<stdio.h>
#include<string.h>
char g[100][100];
int visit[100][100];

int X[]={-1,-1,-1,0,0,1,1,1};
int Y[]={-1,0,1,-1,1,-1,0,1};
/*
bool valid(int x,int y)
{
    return true;
}
*/
void dfs(int x,int y)
{
    int u,v;
    visit[x][y]=1;
    g[x][y]='#';
    //printf("%d",g[x][y]);
    for(int i=0;i<8;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(g[u][v]==' ' && visit[u][v]==0)
            dfs(u,v);
    }
}

int main()
{
    int tc,max,i,j,len,k;
    scanf("%d\n",&tc);
    while(tc--)
    {
        i=0;
        max=0;
        memset(g,' ',sizeof(g));
        memset(visit,0,sizeof(visit));
        while(1)
        {
            gets(g[i]);
            len=strlen(g[i]);
            if(max<len)
            max=len;

            if(g[i][0]=='_')
            break;
            i++;
        }
        for(j=0;j<i;j++)
        {
            for(k=0;k<max;k++)
            if(g[j][k]=='*')
            dfs(j,k);
        }
        for(j=0;j<=i;j++)
        //for(k=0;k<max;k++)
        printf("%s\n",g[j]);

    }
    return 0;


}
