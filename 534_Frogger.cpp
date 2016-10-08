#include<stdio.h>
#include<algorithm>
#include<math.h>

using namespace std;

struct co_ordinate
{
    int x,y;
};

int n;
double d[210][210];
co_ordinate c[210];

void warshal()
{
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
}

void distance()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            d[i][j]=sqrt(((c[i].x-c[j].x)*(c[i].x-c[j].x))+((c[i].y-c[j].y)*(c[i].y-c[j].y)));
}

int main()
{
    int i,t=1;

    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%d %d",&c[i].x,&c[i].y);

        distance();
        warshal();
        printf("Scenario #%d\n",t++);
        printf("Frog Distance = %.3lf\n\n",d[0][1]);
    /*
        for(i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                printf("%.3lf ",d[i][j]);
            printf("\n");
        }
        */
    }
    return 0;
}
