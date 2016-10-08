
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


int main()
{
    int a,b,c,d,e,tc,i,t,cc,dd;
    vector<int>x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&c,&d);
        a=b=c;
        e=d^c;
        if(e)
        {
            i=0;
            while(e)
            {
                if(e&1)
                x.push_back(i);
                i++;
                e>>=1;
            }
            for(i=0;i<x.size()-1;i++)
            {
                t=1<<x[i];
                a|=t;
            }
            t=1<<x[i];
            b|=t;
        }
        cc=a&b;
        dd=a|b;
        if(cc==c && dd==d)
        printf("%d %d\n",a,b);
        else
        printf("-1\n");
        x.clear();
    }
    return 0;
}
