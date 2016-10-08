#include<stdio.h>
#include<map>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
#define REP(i,a,b) for(int i=a;i<=b;i++)
double g[35][35];
int n;
void warshal()
{
    REP(k,1,n)
        REP(i,1,n)
            REP(j,1,n)
                g[i][j]=max(g[i][j],g[i][k]*g[k][j]);
}
void reset()
{
    REP(i,1,n)
    REP(j,1,n)
    g[i][j]=0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    char s1[100],s[100];
    map<string,int>mp;
    int m,t=1;
    double r;
    while(scanf("%d",&n) && n)
    {
        reset();
        mp.clear();
        REP(i,1,n)
        {
            scanf("%s",s);
            mp[s]=i;
        }
        scanf("%d",&m);
        REP(i,1,m)
        {
            scanf("%s %lf %s",s,&r,s1);
            g[mp[s]][mp[s1]]=r;
        }
        /*
        REP(i,1,n)
        {
            REP(j,1,n)
            printf("%.3lf ",g[i][j]);
            printf("\n");
        }
        printf("\n");
        */
        warshal();
        /*
        REP(i,1,n)
        {
            REP(j,1,n)
            printf("%.3lf ",g[i][j]);
            printf("\n");
        }
        printf("\n");
        */
        bool f=false;
        REP(i,1,n)
        if(g[i][i]>1)
        {
            f=true;
            break;
        }
        if(f)
        printf("Case %d: Yes\n",t++);
        else
        printf("Case %d: No\n",t++);
    }
    return 0;
}
