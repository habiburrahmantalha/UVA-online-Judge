#include<stdio.h>
#include<algorithm>
#include<string.h>
#define inf 10000
using namespace std;

int g[85][85],cost[85][85],c,city[85];
void warshal()
{
    int i,j,k;
    for(k=1;k<=c;k++)
        for(i=1;i<=c;i++)
            for(j=1;j<=c;j++)
                g[i][j]=min(g[i][j]+city[i],g[i][k]+g[k][j]+max(city[i],city[j]));

}
void reset()
{
    int i,j;
    for(i=0;i<=c;i++)
        for(j=0;j<=c;j++)
        g[i][j]=10000000;
}



void max_city_cost()
{
    int i,j;
    for(i=0;i<=c;i++)
    {
        for(j=0;j<=c;j++)
        {
            cost[i][j]=max(city[i],city[j]);
        }
    }
}
int main()
{
    int r,q,i,a,b,d,cost;
    while(scanf("%d %d %d",&c,&r,&q))
    {
        reset();
        if(c==0 && r==0 && q==0)
            break;
        for(i=1;i<=c;i++)
            scanf("%d",&city[i]);
        max_city_cost();

        for(i=0;i<r;i++)
        {
            scanf("%d %d %d",&a,&b,&d);
            g[a][b]=d;
            g[b][a]=d;
        }

        warshal();

        for(i=0;i<q;i++)
        {
            scanf("%d %d",&a,&b);

            if(g[a][b]!=inf)
                printf("%d\n",g[a][b]);
            else
                cost=-1;
        }
    }
    return 0;
}
