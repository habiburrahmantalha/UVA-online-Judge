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
					g[i][j]=g[j][i]=min(g[i][j],max(g[i][k],g[k][j]));
        }
    }
}

int main()
{
    int q,v,a,b,c,tc=1;
    bool f=false;
    while(scanf("%d %d %d",&n,&v,&q) && n && v && q)
    {
        if(f==true)
        printf("\n");
        memset(g,0x7F,sizeof(g));

        for(int i=0;i<v;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a][b]=g[b][a]=c;
        }
        warshal(n);
        printf("Case #%d\n",tc++);
        for(int i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);
            if(g[a][b]==2139062143)
            printf("no path\n");
            else
            printf("%d\n",g[a][b]);
        }

        f=true;
    }
    return 0;
}
