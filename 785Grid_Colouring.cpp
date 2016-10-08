#include<stdio.h>
#include<string.h>
char g[35][85];
int visit[35][85];

int X[]={0,-1,0,1};
int Y[]={-1,0,1,0};

/*
bool valid(int x,int y)
{
    return true;
}
*/
void dfs(int x,int y,char ch)
{
    int u,v;
    visit[x][y]=1;
    g[x][y]=ch;

    for(int i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(g[u][v]==' ')
            dfs(u,v,ch);
    }
}

int main()
{
    int tc,max,i,j,len,k;
    //scanf("%d\n",&tc);
    char counters;
    while(1)
    {
        i=0;
        max=0;
        memset(g,0,sizeof(g));
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
        //for(j=0;j<=i;j++)
        //for(k=0;k<max;k++)
        //printf("%s\n",g[j]);
        //printf("%d",max);
        bool f= false;
        for(j=0;j<i;j++)
        {
            for(k=0;k<max;k++)
            {

                if(g[j][k]!=' ' && g[j][k]!='X' && visit[j][k]==0)
                {
                    //printf("%d %d\n",j,k);
                    counters=g[j][k];
                    //printf("%c",counters);
                    dfs(j,k,counters);
                }
            }
        }

        for(j=0;j<=i;j++)
        //for(k=0;k<max;k++)
        printf("%s\n",g[j]);

    }
    return 0;


}
