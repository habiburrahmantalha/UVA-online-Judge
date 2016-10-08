#include<stdio.h>
#include<math.h>
#include<queue>
#include<string.h>
using namespace std;
int n;
double g[101][101],d[101];
int visit[101];
struct c_o
{
    double x,y;
};

c_o fr[101];

double dist(c_o a,c_o b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

void prims()
{
    priority_queue<pair<double,int> >pq;
    pair<double,int>p;
    int a,b,i;

    memset(visit,0,sizeof(visit));
    memset(d,0x7F,sizeof(d));
    pq.push(make_pair(0,0));
    d[0]=0;
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        a=p.second;
        visit[a]=1;
        for(b=0;b<n;b++)
        {
            if(a!=b && visit[b]==0)
            {
                if(d[b]>g[a][b])
                {
                    d[b]=g[a][b];
                    pq.push(make_pair(-d[b],b));
                }
            }
        }
    }
}
void make_graph()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        g[i][j]=dist(fr[i],fr[j]);
    /*for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            printf("%5.2lf",g[i][j]);
        printf("\n");
    }*/
}

int main()
{
    int tc,i;
    double res;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)printf("\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lf %lf",&fr[i].x,&fr[i].y);

        make_graph();

        prims();

        res=0;
        for(i=0;i<n;i++)
            res+=d[i];

        printf("%.2lf\n",res);
        f=true;
    }
    return 0;
}
