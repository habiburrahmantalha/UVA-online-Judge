#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int n,mx;
vector<int> g[30];
int xx[30];
int visit[30][30];
void backtrack(int i,int x)
{

    xx[x]=i;
    int k,j;
    if(mx<x)
    {
        mx=x;
        /*
        for(k=0;k<=x;k++)
            printf("%d ",xx[k]);
        printf("\n");
        */
    }

    for(j=0;j<g[i].size();j++)
    {

        if(visit[i][g[i][j]]==0 && visit[g[i][j]][i]==0)
        {
            visit[i][g[i][j]]=1;
            visit[g[i][j]][i]=1;
            backtrack(g[i][j],x+1);
            visit[i][g[i][j]]=0;
            visit[g[i][j]][i]=0;
        }
        //printf("%d ",i);
    }
}
int main()
{
    int m,i,j,a,b;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
            break;
        mx=0;
        for(i=0;i<30;i++)
            g[i].clear();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        /*
        for(i=0;i<n;i++)
        {for(j=0;j<n;j++)
        printf("%d ",g[i][j]);
        printf("\n");}
        */

        for(i=0;i<n;i++)
        {
            memset(visit,0,sizeof(visit));
            backtrack(i,0);
        }

        printf("%d\n",mx);
    }
    return 0;
}
