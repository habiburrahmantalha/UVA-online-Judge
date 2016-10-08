#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
#include<sstream>
using namespace std;
#define PI 2 * acos (0.0)
double g[210][210];
double xy[210][2];
int n;

double dist(int i,int j)
{
    return sqrt((xy[i][0]-xy[j][0])*(xy[i][0]-xy[j][0])+(xy[i][1]-xy[j][1])*(xy[i][1]-xy[j][1]));
}
void warshal()
{
    int i,j,k;
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
double d[210];
void dijkstra()
{
    priority_queue<pair<double,int> > pq;
    int u,v,i;
    for(i=0;i<210;i++)
            d[i]=200000000.0;
    d[0]=0.0;
    pq.push(make_pair(0.0,0));

    while(!pq.empty())
    {
        u=pq.top().second;pq.pop();
        if(u==1)
        return;
        for(v=0;v<n;v++)
        {
            if(d[v]>g[u][v]+d[u])
            {
                d[v]=g[u][v]+d[u];
                pq.push(make_pair(-d[v],v));
            }
        }
    }

}
int main()
{
    int tc,i,j,k;
    string line,a,b;
    stringstream subway;

    scanf("%d",&tc);

    while(tc--)
    {
        for(i=0;i<210;i++)
            for(j=0;j<210;j++)
                g[i][j]=200000000.0;


        cin>>xy[0][0]>>xy[0][1]>>xy[1][0]>>xy[1][1];
        scanf("\n");
        n=2;
        while(getline(cin,line) && line.size())
        {
            subway.clear();
            subway<<line;
            i=n;
            while(subway>>a>>b && a!="-1" && b!="-1")
            {
                xy[n][0]=atof(a.c_str());
                xy[n][1]=atof(b.c_str());
                n++;
            }

            for(j=i;j<n-1;j++)
                g[j][j+1]=g[j+1][j]=dist(j,j+1)*0.09;

        }
        for(i=0;i<n;i++)
            for(j=i;j<n;j++)
                if(g[i][j]==200000000.0)
                    g[i][j]=g[j][i]=dist(i,j)*0.36;
        //warshal();
        //printf("%.0lf\n",g[0][1]/60.0);

        dijkstra();
        printf("%.0lf\n",d[1]/60.0);
        if(tc)
        printf("\n");
    }
    return 0;
}
