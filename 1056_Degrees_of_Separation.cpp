#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
int n,g[55][55],mx;
#define inf 1<<29

void warshal()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
void reset()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        g[i][j]=inf;
        g[i][i]=0;
    }
}
void degree()
{
    mx=0;
    int i,j;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    mx=max(mx,g[i][j]);
}
int main()
{
    int m,i,j,ind,t=1;
    char a[11000],b[11000];
    map<string,int>mp;
    while(scanf("%d %d",&n,&m) && n)
    {
        ind=1;
        reset();
        for(i=0;i<m;i++)
        {
            scanf("%s %s",a,b);
            if(!mp[a])
            mp[a]=ind++;
            if(!mp[b])
            mp[b]=ind++;
            g[mp[a]][mp[b]]=g[mp[b]][mp[a]]=1;
        }

        warshal();
        degree();
        if(mx==inf)
            printf("Network %d: DISCONNECTED\n\n",t++);
        else
            printf("Network %d: %d\n\n",t++,mx);

        mp.clear();

    }
    return 0;
}
