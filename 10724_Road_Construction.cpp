#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define inf 1000000
using namespace std;

struct co_ord
{
    double x,y;
};
int n;
double g[55][55],p[55][55];

void warshal()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(g[i][j]>g[i][k]+g[k][j])
                g[i][j]=g[i][k]+g[k][j];
}

void warshal(double h[55][55],int a,int b)
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(h[i][j]>h[i][k]+h[k][j])
                h[i][j]=h[i][k]+h[k][j];
}

co_ord exies[55];

double dist(int i,int j)
{
    double d;
    d=sqrt((exies[i].x-exies[j].x)*(exies[i].x-exies[j].x)+(exies[i].y-exies[j].y)*(exies[i].y-exies[j].y));
    return d;
}
int main()
{

    int a,b,c,mn,i,j,m,x;
    while(scanf("%d %d",&n,&m) && n && m)
    {

        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                g[i][j]=inf;

        for(i=1;i<=n;i++)
        scanf("%lf %lf",&exies[i].x,&exies[i].y);

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            g[a][b]=g[b][a]=dist(a,b);
            p[a][b]=p[b][a]=g[a][b];
            c[a][b]=1;
        }

        warshal();
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            if(i!=j)
            {
                c[i][j]==0;
                p[i][j]=dist(i,j);
                warshal(p,i,j);
            }

        }


    }
    return 0;
}
