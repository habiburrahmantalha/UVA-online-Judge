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

long long gcd(long long a, long long b)
{
   return b?gcd(b,a%b):a;
}


int main()
{
    long long i,j,k,n,a,b,c,cnt,cntp;
    bool f[1000010];
    memset(f,false,sizeof(f));
    while(scanf("%lld",&n)==1)
    {
        cnt=0;
        cntp=0;
        for(i=1;i*i<=n;i++)
        {
            for(j=i+1;i*i+j*j<=n;j++)
            {
                a=j*j-i*i;
                b=2*i*j;
                c=i*i+j*j;

                if(gcd(a,gcd(b,c))==1)
                {
                    cnt++;
                    for(k=1;k*c<=n;k++)
                    {
                        f[a*k]=true;
                        f[b*k]=true;
                        f[c*k]=true;
                    }
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(f[i])
                f[i]=false;
            else
                cntp++;
        }
        printf("%lld %lld\n",cnt,cntp);

    }
    return 0;
}
