#include<stdio.h>
#include<string.h>
#define  FOR(i,x,y) for(i=x;i<=y;i++)
#include<algorithm>

using namespace std;

struct oasis
{
    int u,v;
    double t,d;
};
double gt[110][110],gd[110][110];
int pi[110][110];
int n,m;
oasis edge[10010];

void temparature()
{
    int i,j,k;
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n)
                gt[i][j]=min(gt[i][j],max(gt[i][k],gt[k][j]));

}

void distance()
{
    int i,j,k;
    FOR(k,1,n)
        FOR(i,1,n)
            FOR(j,1,n)
            {
                if(gd[i][j]>gd[i][k]+gd[k][j])
                {
                    gd[i][j]=gd[i][k]+gd[k][j];
                    pi[i][j]=pi[k][j];
                }
            }
}

void print_path(int i,int j)
{
    if(i==j)
    {
        printf("%d",i);
    }
    else
    {
        print_path(i,pi[i][j]);
        printf(" %d",j);
    }

}
void reset()
{
    int i,j;
    FOR(i,1,n)
    {
        FOR(j,1,n)
        {
            gt[i][j]=1000000;
            gd[i][j]=1000000;
            pi[i][j]=i;
        }
        gt[i][j]=0;
        gd[i][j]=0;
    }

}
void set_distance(double x)
{
    int i,u,v;
    FOR(i,1,m)
    {
        u=edge[i].u;
        v=edge[i].v;
        if(gd[u][v]>edge[i].d && edge[i].t<=x)
        {
            gd[u][v]=gd[v][u]=edge[i].d;
        }
    }
}
int main()
{
    int a,b,i,s,e;
    double t,d;
    while(scanf("%d %d",&n,&m)==2)
    {
        reset();
        scanf("%d %d",&s,&e);
        FOR(i,1,m)
        {
            scanf("%d %d %lf %lf",&a,&b,&t,&d);
            edge[i].u=a;
            edge[i].v=b;
            edge[i].d=d;
            edge[i].t=t;

            if(gt[a][b]>t)
            {
                gt[a][b]=t;
                gt[b][a]=t;
            }
        }
        temparature();
        set_distance(gt[s][e]);
        distance();
        print_path(s,e);
        printf("\n");
        printf("%.1lf %.1lf\n",gd[s][e],gt[s][e]);
    }
    return 0;
}
