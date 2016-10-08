#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>

using namespace std;

int g[30][30],visit[30][30],n,node[30];

void dfs_visit(int s)
{
    int i;
    node[s]=1;
    for(i=0;i<=n;i++)
    {
        if(g[s][i] && visit[s][i]==0)
        {
            visit[s][i]=1;
            dfs_visit(i);
        }
    }
}

void dfs()
{
    int i,j,count=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        if(g[i][j] && visit[i][j]==0)
        {
            count++;
            dfs_visit(i);
        }
    }
    i=0;
    while(i<=n)
    {
        if(node[i]==0)
            count++;
        i++;
    }
    printf("%d\n",count);
}

int main()
{
    int tc,i,a,b;
    string str;
    char h_n[3],ch;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        memset(node,0,sizeof(node));
        if(f)
            printf("\n");
        scanf("%s",h_n);
        ch=getchar();
        n=h_n[0]-'A';

        while(1)
        {
            getline(cin,str);
            if(str.size()==0)
                break;

            a=str[0]-'A';
            for(i=1;i<str.size();i++)
            {
                b=str[i]-'A';
                g[a][b]=1;
                g[b][a]=1;
                a=b;
            }
        }

        dfs();
        f=true;
    }
    return 0;
}
