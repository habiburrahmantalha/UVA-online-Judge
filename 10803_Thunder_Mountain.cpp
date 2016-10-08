#include<stdio.h>
#include<string.h>
#include<math.h>
#define inf 10000000
struct co_ordinate
{
    double x,y;
};

int n;
double g[110][110];
co_ordinate c[110];

void warshal ()
{
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(g[i][j]>g[i][k]+g[k][j])
                g[i][j]=g[i][k]+g[k][j];

}
bool Send_Kurdy()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(i!=j)
                if(g[i][j]==inf)
                return true;
    }
    return false;
}

void distance()
{
    int i,j;
    double dist;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(i!=j)
        {
            dist=(c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y);
            if(dist<=100)
                g[i][j]=sqrt(dist);
        }
}
void reset()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            g[i][j]=inf;
}
int main()
{
    int i,j,tc,t;
    double max;

    scanf("%d",&tc);

    for(t=1;t<=tc;t++)
    {
        scanf("%d",&n);

        reset();

        for(i=0;i<n;i++)
            scanf("%lf %lf",&c[i].x,&c[i].y);
        distance();
        warshal();

        max=0;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(i!=j && g[i][j]!=inf && max<g[i][j])
                    max=g[i][j];
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%6.0lf",g[i][j]);
            printf("\n");
        }
        */

        if(Send_Kurdy())
            printf("Case #%d:\nSend Kurdy\n\n",t);
        else
            printf("Case #%d:\n%.4lf\n\n",t,max);
    }
    return 0;
}
