#include<stdio.h>
#include<string.h>
#include<map>
#include<iostream>
#include<math.h>
#define pi 3.141592653589793
#define LL long long
#define inf 2139062143
using namespace std;

int n;
long long g[101][101];
struct co_ord
{
    double lt,ln;
};

void warshal()
{
    int i,j,k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}
int main()
{
    int m,q,i,j,t=1;
    co_ord l[101];
    map<string,int>mp;
    string city,city1,city2;
    long long temp;
    while(scanf("%d %d %d",&n,&m,&q))
    {
        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
            if(i==j)
                g[i][j]=0;
            else
                g[i][j]=inf;

        if(n==0 && m==0 && q==0)
            break;

        for(i=1;i<=n;i++)
        {

            cin>>city>>l[i].lt>>l[i].ln;
            l[i].lt=(l[i].lt*pi)/180;
            l[i].ln=(l[i].ln*pi)/180;
            if(!mp[city])
                mp[city]=i;
        }

        for(i=0;i<m;i++)
        {
            cin>>city1>>city2;
            temp=(long long )(acos((sin(l[mp[city1]].lt))*sin(l[mp[city2]].lt)+(cos(l[mp[city1]].lt))*cos(l[mp[city2]].lt)*cos(l[mp[city1]].ln-l[mp[city2]].ln)));

            g[mp[city1]][mp[city2]]= temp*6378;

        }
        warshal();
        printf("Case #%d\n",t++);
        for(i=0;i<q;i++)
        {
            cin>>city1>>city2;
            if(g[mp[city1]][mp[city2]]==inf)
                printf("no route exists\n");
            else
            printf("%lld km\n",g[mp[city1]][mp[city2]]);
        }
        mp.clear();
    }

    return 0;
}
