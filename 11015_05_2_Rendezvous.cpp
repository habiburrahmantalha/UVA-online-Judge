#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf 10000000
using namespace std;

struct place
{
    char name[12];
    int cost;
};

int n,g[30][30];

void warshal()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(g[i][j]>g[i][k]+g[k][j])
                g[i][j]=g[i][k]+g[k][j];
}

int main()
{
    place P[30];
    int a,b,c,mn,i,j,m,x,tc=1;
    while(scanf("%d %d",&n,&m))
    {
        if(n==0 && m==0)
        break;

        for(i=1;i<=n;i++)
            P[i].cost=0;
        //memset(g,0,sizeof(g));
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                g[i][j]=inf;

        for(i=1;i<=n;i++)
        scanf("%s",P[i].name);

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            g[a][b]=g[b][a]=c;
        }

        warshal();

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(i!=j)
                    P[i].cost+=g[i][j];

            }
        }
        mn=inf*n;
        for(i=1;i<=n;i++)
        {
            if(mn>P[i].cost)
            {
                mn=P[i].cost;
                x=i;
            }
        }
        printf("Case #%d : %s\n",tc++,P[x].name);
    }
    return 0;
}
