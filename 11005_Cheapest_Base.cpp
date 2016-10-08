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
int cost[40];
int base(long long x,long long b)
{
    int c=0;
    while(x!=1 && x>=b)
    {
        c+=cost[x%b];
        //cout<<x%b<<" ";
        x/=b;


    }
    c+=cost[x];
    //cout<<c<<endl;
    return c;
}

int main()
{
    /*
    int y;
    scanf("%d",&y);
    for(int i=2;i<36;i++)
    {

        base(y,i);
    }
    //*/
    int tc,c,i,q,mn,base_cost,t=1;
    long long x;
    int v[40];
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<36;i++)
        scanf("%d",&cost[i]);

        printf("Case %d:\n",t++);
        scanf("%d",&q);

        while(q--)
        {

            scanf("%lld",&x);
            mn=2000000001;
            for(i=2;i<=36;i++)
            {
                base_cost=base(x,i);
                mn=min(mn,base_cost);
                v[i]=base_cost;
            }

            printf("Cheapest base(s) for number %lld:",x);
            for(i=2;i<=36;i++)
            {
                if(v[i]==mn)
                printf(" %d",i);
            }
            printf("\n");

        }
        if(tc!=0)
        printf("\n");
    }
    return 0;
}
