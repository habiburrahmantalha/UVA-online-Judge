#include<map>
#include<string>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
# define inf 9187201950435737471
using namespace std;

long long g[405][405],d[405],visit[405],m,n;

void prims(int s)
{
    priority_queue<pair<long long,long long> >pq;
    pair<long long,long long>p;
    int a,b;
    pq.push(make_pair(0,s));
    d[s]=0;
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        a=p.second;
        visit[a]=1;
        for(b=1;b<=n;b++)
        {
            if(g[a][b] && visit[b]==0)
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

int main()
{
    long long i,j,c,res;
    map<string,long long>mp;
    char s1[20],s2[20];
    while(scanf("%lld %lld",&n,&m) )
    {
        if(n==0 && m==0)
            break;
        memset(g,0,sizeof(g));
        memset(visit,0,sizeof(visit));
        memset(d,0x7F,sizeof(d));

        for(i=1;i<=n;i++)
        {
            scanf("%s",s1);
            mp[s1]=i;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s %s %lld",s1,s2,&c);
            g[mp[s1]][mp[s2]]=g[mp[s2]][mp[s1]]=c;

        }
        scanf("%s",s1);
        prims(mp[s1]);
        res=0;
        for(i=1;i<=n;i++)
        if(d[i]==inf)
        {
            res=inf;
            break;
        }
        else
            res+=d[i];
        if(res>=inf)
            printf("Impossible\n");
        else
            printf("%lld\n",res);
    }


    return 0;
}
