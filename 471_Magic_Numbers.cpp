//Problem Type :
//Time : 0.24
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

bool no_repeate(long long x)
{
    bool f[10];
    memset(f,false,sizeof(f));
    while(x)
    {
        if(f[x%10])
            return false;
        f[x%10]=true;
        x/=10;
    }
    return true;

}


int main()
{

    int tc;
    long long i,x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%lld",&x);
        for(i=1;i*x<=10000000000 ;i++)
        {
            if(no_repeate(i) && no_repeate(i*x))
            printf("%lld / %lld = %lld\n",i*x,i,x);
        }
        if(tc!=0)
        printf("\n");
    }
    return 0;
}
