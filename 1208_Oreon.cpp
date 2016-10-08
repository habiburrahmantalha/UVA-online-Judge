#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,pair<int,int> > >graph,MST;
int n,m,P[30],mst;

void reset()
{
    int i;
    for(i=0;i<n;i++)
    P[i]=i;
}

bool comp(pair<int,pair<int,int> >  i,pair<int,pair<int,int> >  j)
{
    if(i.first==j.first)
    {
        if(i.second.first==j.second.first)
            return i.second.second<j.second.second;
        return i.second.first<j.second.first;
    }
    return i.first<j.first;

}

int find(int x)
{
   if(P[x]!=x)
   P[x]=find(P[x]);
   return P[x];
}

void krushkal()
{
    int u,v,i;
    mst=0;
    for(i=0;i<m;i++)
    {
        u=find(graph[i].second.first);
        v=find(graph[i].second.second);

        if(u!=v)
        {
            P[u]=P[v];
            MST.push_back(graph[i]);
            mst++;

            if(mst==n-1)
            break;
        }
    }
}
void print_mst()
{
    for(int i=0;i<mst;i++)
    printf("%c-%c %d\n",MST[i].second.first+'A',MST[i].second.second+'A',MST[i].first);
}
int main()
{
    int tc,t=1,a,b,c;
    char ch;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        reset();
        m=0;
        for(a=0;a<n;a++)
        {
            for(b=0;b<n-1;b++)
            {
                scanf("%d%c",&c,&ch);
                if(c!=0 && a<b)
                {
                    graph.push_back(make_pair(c,make_pair(a,b)));
                    m++;
                }
            }
            scanf("%d",&c);
            if(c!=0 && a<b)
            {
                graph.push_back(make_pair(c,make_pair(a,b)));
                m++;
            }
        }
        sort(graph.begin(),graph.end(),comp);
        krushkal();

        //sort(MST.begin(),MST.end(),comp);
        printf("Case %d:\n",t++);
        print_mst();

        graph.clear();
        MST.clear();
    }
    return 0;
}
