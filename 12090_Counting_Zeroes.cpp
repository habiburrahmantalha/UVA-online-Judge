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


int main()
{
    vector<long long>v;
    long long i,n,c,x;
    while(scanf("%lld",&n) && n)
    {
        for(i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                v.push_back(i);
                v.push_back(n/i);
            }
        }
        c=0;
        for(i=0;i<v.size();i++)
        {
            x=n;
            while(x%v[i]==0)
            {
                c++;
                x/=v[i];
            }
        }
        printf("%lld %lld\n",n,c+1);
        v.clear();
    }
    return 0;
}
