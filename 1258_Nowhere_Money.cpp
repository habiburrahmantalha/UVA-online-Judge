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

long long fib[100];
void precal()
{
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<91;i++)
    fib[i]=fib[i-2]+fib[i-1];
}
int main()
{
    precal();
    long long n;
    vector<int>res;
    int i,j ;

    while(scanf("%lld",&n)==1)
    {

        printf("%lld\n",n);
        i=90;
        j=0;
        while(n)
        {
            if(n>=fib[i])
            {
                res.push_back(i);
                n-=fib[i];

            }
            i--;
            j++;
        }

        for(i=0;i<res.size();i++)
        printf("%lld ",res[i]);
        printf("\n");


        for(i=0;i<res.size();i++)
        printf("%lld ",fib[res[i]]);
        printf("\n\n");
        res.clear();
    }
    return 0;
}
