#include<map>
#include<string>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
# define inf 9187201950435737471
using namespace std;
#define LL long long
LL m,n,mst,res;
vector<pair<LL,pair<LL,LL> > > graph;

LL P[410];

void reset() //reset parent
{
    LL i;
    for(i=0;i<=n;i++)
        P[i] = i;
}
LL findset(LL x)  //find parent
{
    if(x != P[x])
        P[x] = findset(P[x]);
    return P[x];
}

void krushkal()
{
    LL i,pu,pv;
    mst=res=0;
    for(i=0;i<m;i++)
    {

        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);

        if(pu!=pv)
        {
            res+=graph[i].first;

            //MST.push_back(graph[i]);
            P[pu]=P[pv]; //find circle
            mst++;
            if(mst==n-1)
            break;
        }

    }
}

int main()
{
    LL i,j,c;
    map<string,LL>mp;
    char s1[20],s2[20];
    while(scanf("%lld %lld",&n,&m) )
    {
        if(n==0 && m==0)
            break;
        for(i=1;i<=n;i++)
        {
            scanf("%s",s1);
            mp[s1]=i;
        }
        reset();
        for(i=0;i<m;i++)
        {
            scanf("%s %s %lld",s1,s2,&c);
            graph.push_back(make_pair(c,make_pair(mp[s1],mp[s2])));

        }
        scanf("%s",s1);
        sort(graph.begin(),graph.end());
        krushkal();

        if(mst!=n-1)
            printf("Impossible\n");
        else
            printf("%lld\n",res);
        graph.clear();
        mp.clear();
    }

    return 0;
}

