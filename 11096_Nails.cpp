//Problem Type :
//Time :
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

struct nail
{
    int x,y;

    nail(int x,int y): x(x),y(y){}
    bool operator < (const nail &that) const
    {
        if(x==that.x)
            return y < that.y;
        return x < that.x;

    }

};

vector<nail>p;
double dist(nail a,nail b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
    int tc,i,n,m,a,b;
    double d;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);

        for(i=0;i<m;i++)
        {
            scanf("%d %d",&a,&b);
            p.push_back(nail(a,b));
        }
        sort(p.begin(),p.end());
        d=0;
        for(i=0;i<m-1;i++)
        {
            d+=dist(p[i],p[i+1]);

        }
        //d+=dist(p[0],p[i]);
        if(d<n)
        d=n;
        printf("%.5lf\n",d);

    }
    return 0;
}
