#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#define REP(x,i,j) for(x=i;x<j;x++) //for loop :P
#include<math.h>
using namespace std;
#define LL long long
struct co_ordinate
{
    double x,y;
};

LL n,m,mst,s;
double cost;
LL P[1010];
vector<pair<double,pair<LL,LL> > > graph,MST;  //graph (weight,a,b )

void reset() //reset parent
{
    LL i;
    REP(i,0,n) P[i] = i;
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
    mst=cost=0;
    REP(i,0,m)
    {

        pu=findset(graph[i].second.first);
        pv=findset(graph[i].second.second);
        if(pu!=pv)
        {

            P[pu]=P[pv]; //find circle
            mst++;

            if(mst==n-s)
            {
                cost=graph[i].first;
                break;
            }
        }

    }
}
double dist(co_ordinate x,co_ordinate y)
{
    double z=sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));
    return z;

}

int main()
{
    //freopen("in.txt","r",stdin);
    co_ordinate city[1010];
    double c;
    LL i,j,tc;
    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld %lld",&s,&n);
        reset();
        REP(i,0,n)
            scanf("%lf %lf",&city[i].x,&city[i].y);
        m=0;
        REP(i,0,n)
        REP(j,0,n)
        if(i!=j)
        {

            c=dist(city[i],city[j]);
            //printf("%lld %lld %lf\n",i,j,c);
            graph.push_back(make_pair(c,make_pair(i,j)));
            m++;
        }


        sort(graph.begin(),graph.end());
        krushkal();

        printf("%.2lf\n",cost);

        graph.clear();
    }
    return 0;
}
