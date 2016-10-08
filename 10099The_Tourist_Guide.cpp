#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;


int g[110][110],n;

void warshal(int n)
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                g[i][j]=max(g[i][j],min(g[i][k],g[k][j]));
        }
    }
}

int main()
{
    int v,a,b,c,tc=1,ans;

    while(scanf("%d %d",&n,&v) && n && v)
    {

        memset(g,0,sizeof(g));

        for(int i=0;i<v;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            c--;
            g[a][b]=g[b][a]=c;
        }
        warshal(n);
        scanf("%d %d %d",&a,&b,&c);
        printf("Scenario #%d\n",tc++);
        if(a==b)
        printf ("Minimum Number of Trips = 1\n\n");
        else
        {
            ans=c/g[a][n];
            if(ans*g[a][n]<c)
            ans++;
            printf("Minimum Number of Trips = %d\n\n",ans);
        }
    }
    return 0;
}
