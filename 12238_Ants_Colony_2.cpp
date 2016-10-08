//Problem Type : LCA,prims,bfs
//Time : 500
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

int pi[100010],l[100010];
long long d[100010];

int n;

int main()
{
    int i,a,b,q;
    long long c;
    while(scanf("%d",&n) && n)
    {

        d[0]=l[0]=pi[0]=0;
        for(i=1;i<n;i++)
        {
            scanf("%d %lld",&a,&c);
            d[i]=d[a]+c;
            l[i]=l[a]+1;
            pi[i]=a;

        }

        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
            c=d[a]+d[b];
            while(a!=b)
            {
                if(l[a]==l[b])
                {
                    a=pi[a];
                    b=pi[b];
                }
                else if(l[a]>l[b])
                {
                    a=pi[a];
                }
                else
                {
                    b=pi[b];
                }
            }
            //printf("%d %d %d %d\n",pi[a],pi[b],a,b);
            if(q)
            printf("%lld ",c-d[a]-d[b]);
            else
            printf("%lld\n",c-d[a]-d[b]);

        }
    }
    return 0;
}
