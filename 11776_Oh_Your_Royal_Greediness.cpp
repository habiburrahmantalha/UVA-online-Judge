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

struct T
{
    int S,E;
};
bool cmp(T a,T b)
{
    return a.S<b.S;
}


int main()
{
    T x[1010];
    bool v[1010];
    int n,i,j,p,cnt,t=1;
    while(scanf("%d",&n) && n!=-1)
    {
        for(i=0;i<n;i++)
            scanf("%d %d",&x[i].S,&x[i].E);
        sort(x,x+n,cmp);

        memset(v,false,sizeof(v));
        cnt=0;
        for(i=0;i<n;i++)
        {
            if(!v[i])
            {
                cnt++;
                v[i]=true;
                p=x[i].E;
                for(j=i+1;j<n;j++)
                {
                    if(!v[j] && p<x[j].S)
                    {
                        v[j]=true;
                        p=x[j].E;

                    }
                }
            }
        }
        printf("Case %d: %d\n",t++,cnt);
    }

    return 0;
}
