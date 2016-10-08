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

long long fib[90];

void fibonacci()
{
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<90;i++)
    fib[i]=fib[i-1]+fib[i-2];



}

int main()
{
    fibonacci();
    long long x;
    int tc,i;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%lld",&x);
        printf("%lld = ",x);
        f=false;
        for(i=85;i>=1;i--)
        {
            if(x>=fib[i])
            f=true;
            if(f)
            {
                if(x>=fib[i])
                {
                    printf("1");
                    x-=fib[i];
                }
                else
                printf("0");
            }
        }
        printf(" (fib)\n");
    }
    return 0;
}
