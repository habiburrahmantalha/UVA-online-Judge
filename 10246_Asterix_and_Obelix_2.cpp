#include<stdio.h>
#include<algorithm>
#include<string.h>
#define inf 10000
using namespace std;

struct city_cost
{
    int n,cost;
};


int g[85][85],c,cost;
city_cost city[85];
void warshal()
{
    int i,j,k;
    for(k=1;k<=c;k++)
        for(i=1;i<=c;i++)
            for(j=1;j<=c;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);

}
void reset()
{
    int i,j;
    for(i=0;i<=c;i++)
        for(j=0;j<=c;j++)
        g[i][j]=inf;
}

bool comp(city_cost a,city_cost b)
{
    return a.cost>b.cost;
}
bool total_cost(int a,int b)
{
    cost=inf;
    for(int i=1;i<=c;i++)
    {
        if(g[a][city[i].n]!=inf && g[city[i].n][b]!=inf)
        {
            cost=min(cost,g[a][city[i].n]+g[city[i].n][b]);
            //return true;
        }
    }
    if(cost==inf)
    return false;
    else
        return true;
}

int main()
{
    int r,q,i,a,b,d;

    while(scanf("%d %d %d",&c,&r,&q))
    {
        reset();
        if(c==0 && r==0 && q==0)
            break;
        for(i=1;i<=c;i++)
        {
            city[i].n=i;
            scanf("%d",&city[i].cost);
        }
        sort(city+1,city+c,comp);


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

            if(total_cost(a,b))
                printf("%d\n",cost);
            else
                printf("-1\n");
        }
    }
    return 0;
}
