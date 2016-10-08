#include<stdio.h>
#include<string.h>
#include<sstream>
#include<iostream>
#include<string>
using namespace std;
#define LL long long
LL n,w,c;
LL g[1001][1001],visit[1001][1001];
LL X[]={1,0};
LL Y[]={0,1};

bool valid(LL x,LL y)
{
    if(x<1 || x>w || y<1 || y>n)
    return false;
    return true;
}
void count_path(LL x,LL y)
{
    LL i,u,v;
    if(x==w && y==n)
    {
        c++;
        return;
    }
    for(i=0;i<2;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && g[u][v]==0 && visit[u][v]==0)
        {
            visit[u][v]=1;
            count_path(u,v);
            visit[u][v]=0;
        }
    }
}
int main()
{
    LL tc,a,b,i;
    bool f=false;
    char ch,line[10001];
    string str;
    scanf("%lld",&tc);

    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        scanf("%lld %lld",&w,&n);
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        gets(line);
        for(i=0;i<w;i++)
        {
            getline(cin,str);
            stringstream ss(str);
            ss>>a;
            while(ss>>b)
            {
                g[a][b]=1;
            }
        }
        /*
        for(i=1;i<=w;i++)
        {
            for(int j=1;j<=n;j++)
            printf("%d ",g[i][j]);
            printf("\n");
        }
        */
        c=0;
        visit[1][1]=1;
        count_path(1,1);
        printf("%lld\n",c);
    }
    return 0;
}
