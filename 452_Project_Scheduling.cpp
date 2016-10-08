#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<ctype.h>
using namespace std;
int g[100][100],visit[100],V[100],n,in,c[100],mx;
void dfs(int u)
{
    visit[u]=1;
    for(int v=0;v<=n;v++)
    {
        if(g[u][v] && visit[v]==0)
        dfs(v);
    }
    V[in--]=u;
}

void dfs2(int u,int t,int k)
{
    //printf("->%d%c ",t,u+'A');
    mx=max(mx,t);
    for(int i=k+1;i<=n;i++)
    if(g[u][V[i]])
    dfs2(V[i],t+c[V[i]],i);
}
int main()
{
    int tc,d,i,a,b;
    char input[100],temp[10];
    bool f=false;
    scanf("%d",&tc);
    gets(input);
    gets(input);
    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        n=0;
        memset(g,0,sizeof(g));
        memset(c,0,sizeof(c));
        while(gets(input))
        {
            if(strlen(input)==0)
            break;
            a=input[0]-'A';

            in=0;
            memset(temp,0,sizeof(temp));
            for(i=2;isdigit(input[i]);i++)
            temp[in++]=input[i];
            c[a]=atoi(temp);
            n=max(n,a);
            i++;
            if(isalpha(input[i]) && i<strlen(input))
            {
                for(;input[i]!=0;i++)
                {
                    b=input[i]-'A';
                    g[b][a]=1;
                    n=max(n,b);
                }
            }
        }
        /*
        for(i=0;i<=n;i++)
        {
            printf("%c->",i+'A');
            for(int j=0;j<=n;j++)
            if(g[i][j])
            printf("%c",j+'A');
            printf("\n");
        }
        for(i=0;i<=n;i++)
        printf("%d\n",c[i]);

        */
        in=n;
        memset(visit,0,sizeof(visit));
        for(i=0;i<=n;i++)
        if(visit[i]==0)
        dfs(i);

        /*
        for(i=0;i<=n;i++)
        printf("%c",V[i]+'A');
        printf("\n");
        */
        mx=0;
        for(i=0;i<=n;i++)
            dfs2(V[i],c[V[i]],i);

        printf("%d\n",mx);
    }
    return 0;
}
