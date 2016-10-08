#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#define inf 2000000
using namespace std;
int g[510][510],n;
vector<int> fire;
vector<pair<int,int> > res;
bool F[510];
int d[510];

void warshal()
{
    int i,j,k;

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            {
                g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
            }
}
void print()
{
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        printf("%d %d %d\n",i,j,g[i][j]);
}
int nearest(int x)
{
    int i,mn=inf;
    for(i=0;i<fire.size();i++)
    mn=min(mn,g[x][fire[i]]);

    return mn;
}
bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
void fire_station()
{
    int i,j,mx;
    fire.push_back(0);

    for(i=1;i<=n;i++)
    {
        if(!F[i])
        {
            fire[fire.size()-1]=i;
            for(j=1;j<=n;j++)
                d[j]=nearest(j);
            mx=0;
            for(j=1;j<=n;j++)
                mx=max(mx,d[j]);
            res.push_back(make_pair(mx,i));
        }

    }
    sort(res.begin(),res.end(),cmp);
    if(res.size())
    printf("%d\n",res[0].second);
    else
    printf("1\n");
}
void reset()
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            g[i][j]=inf;
        g[i][i]=0;
    }
    memset(F,false,sizeof(F));
    fire.clear();
    res.clear();
}
int main()
{
    int tc,i,j,f,x,a,b,c;
    char str[20];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&f,&n);
        reset();
        for(i=0;i<f;i++)
        {
            scanf("%d",&x);
            fire.push_back(x);
            F[x]=true;
        }

        gets(str);
        while(gets(str) && strlen(str)!=0)
        {
            sscanf(str,"%d %d %d",&a,&b,&c);
            g[a][b]=g[b][a]=c;
        }
        warshal();

        fire_station();
        if(tc)
        printf("\n");
        //print();
    }
    return 0;
}
