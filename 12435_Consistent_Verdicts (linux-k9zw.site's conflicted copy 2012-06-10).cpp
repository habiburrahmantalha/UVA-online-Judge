#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;


int main()
{
    long long d,x[1100],y[1100];
    int tc,t=1,n,i,j;
    set<long long>s;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%lld %lld",&x[i],&y[i]);

        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                s.insert(d);
            }
        printf("Case %d: %d\n",t++,s.size()+1);
        s.clear();
    }
    return 0;
}
