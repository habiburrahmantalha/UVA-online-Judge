//line Intersection on segment
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
using namespace std;
#define PI 2 * acos (0.0)
#define EPS 1e-9

struct point
{
    int x,y;
};

struct line
{
    point Start,End;
};
int direction(point a, point b, point c)
{
    //return (c.x*(a.y-b.y)+c.y*(a.x-b.x)+a.y*(a.x-b.x)-a.x*(a.y-b.y));
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x));
}
bool segment(point a, point b, point c)
{
    if( ( (a.x<=c.x || b.x<=c.x) && (c.x<=a.x || c.x<=b.x ) ) && ( (a.y<=c.y || b.y<=c.y) && (c.y<=a.y || c.x<=b.y ) ) )
        return true;
    return false;
}
bool Intersect( point a, point b, point c, point d)
{
    if(direction(a,b,c)==0 && segment(a,b,c))
        return true;
    if(direction(a,b,d)==0 && segment(a,b,d))
        return true;
    if(direction(c,d,a)==0 && segment(c,d,a))
        return true;
    if(direction(c,d,b)==0 && segment(c,d,b))
        return true;
    if( ( ( direction(a,b,c)>0 && direction(a,b,d)<0 ) || ( direction(a,b,c)<0 && direction(a,b,d)>0 ) ) &&
        ( ( direction(c,d,a)>0 && direction(c,d,b)<0 ) || ( direction(c,d,a)<0 && direction(c,d,b)>0 ) ) )
        return true;

    return false;
}
bool G[15][15];
int V[15];
int n;
void dfs(int u,int c)
{
    V[u]=c;
    for(int v=0;v<n;v++)
    {
        if(!V[v] && G[u][v])
            dfs(v,c);
    }

}








int main()
{
    vector<line> L;
    line x;
    int tc,i,j,a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d %d",&x.Start.x,&x.Start.y,&x.End.x,&x.End.y);
            L.push_back(x);
        }
        memset(G,false,sizeof(G));
        for(i=0;i<L.size();i++)
        {
            for(j=i+1;j<L.size();j++)
            {
                if(Intersect(L[i].Start,L[i].End,L[j].Start,L[j].End))
                {
                    G[i][j]=G[j][i]=true;
                }
            }
        }
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d ",G[i][j]);
            printf("\n");
        }
        */
        memset(V,0,sizeof(V));
        int c=1;
        for(i=0;i<n;i++)
            if(!V[i])
            dfs(i,c++);
        while(scanf("%d %d",&a,&b) && a+b)
        {

            if(V[a-1]==V[b-1])
                printf("CONNECTED\n");
            else
                printf("NOT CONNECTED\n");
        }
        L.clear();
        if(tc)
            printf("\n");

    }
    return 0;
}
