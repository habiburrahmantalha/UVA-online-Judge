#include<stdio.h>
#include<queue>
#include<math.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct co_ord
{
    double x,y;
};
double v,t;
int n;
co_ord s,e,x[1010];
int g[1010][1010];
int d[1010];

void bfs()
{
    //for(int i=0;i<n;i++)
    {
        //for(int j=0;j<n;j++)
            //printf("%d ",g[i][j]);
       //printf("\n");
    }
    int u,v;
    queue <int> q;
    q.push(0);
    memset(d,-1,sizeof(d));
    d[0]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=0;v<n;v++)
        {
            if(g[u][v] && d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
                //printf("%d\n",v);
            }
        }
    }
    if(d[n-1]==-1)
        printf("No.\n");
    else
    printf("Yes, visiting %d other holes.\n",d[n-1]-1);
}

double dist(co_ord x,co_ord y)
{
    //printf("%lf %lf %lf %lf\n",x.x,x.y,y.x,y.y);
    return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
}
void graph()
{
    int i,j;
    memset(g,0,sizeof(g));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                //printf("%d %d %lf %lf\n",i,j,dist(x[i],x[j]),v*t*60);

                if(dist(x[i],x[j])<=v*t*60 )
                g[i][j]=g[j][i]=1;
            }
        }
    }
}

int main()
{
    int i;

    char line[50],a[20],b[20];
    while(scanf("%lf %lf",&v,&t))
    {
        if(t==0 && v==0)
            break;
        scanf("%lf %lf",&s.x,&s.y);
        scanf("%lf %lf",&e.x,&e.y);

        getchar();
        n=0;
        x[n++]=s;
        while(gets(line))
        {
            if(strlen(line)==0)
                break;
            sscanf(line,"%s %s",a,b);;
            x[n].x=strtod(a,NULL);
            x[n].y=strtod(b,NULL);
            //printf("%lf %lf\n",x[n].x,x[n].y);
            n++;
        }
        x[n++]=e;
        graph();
        bfs();

    }
    return 0;
}
