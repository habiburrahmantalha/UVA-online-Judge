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
    long long a,b,n;
    while(scanf("%lld %lld %lld",&a,&b,&n)==3 && a+b+n)
    {
        switch(n%5)
        {
            case 0:
            {
                printf("%lld\n",a);
                break;
            }
            case 1:
            {
                printf("%lld\n",b);
                break;
            }
            case 2:
            {
                printf("%lld\n",(1+b)/a);
                break;
            }
            case 3:
            {
                printf("%lld\n",(1+a+b)/(a*b));
                break;
            }
            case 4:
            {
                printf("%lld\n",(a+1)/b);
                break;
            }
        }
    }
    return 0;
}
