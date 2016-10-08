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

struct Time
{
    int brief,complete;
    bool operator < (const Time &that) const
    {
        if(complete==that.complete)
            return brief > that.brief;
        return complete>that.complete;
    }
};


Time x[1010];

int main()
{
    int n,i,t,T,tc=1;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%d %d",&x[i].brief,&x[i].complete);

        sort(x,x+n);

        T=x[0].brief;
        t=x[0].complete;
        for(i=1;i<n;i++)
        {
            T+=x[i].brief;

            if(t>x[i].brief)
            {

                t=t-x[i].brief;
                t=max(x[i].complete,t);
            }
            else
                t=x[i].complete;
        }
        T+=t;
        printf("Case %d: %d\n",tc++,T);
    }
    return 0;
}
