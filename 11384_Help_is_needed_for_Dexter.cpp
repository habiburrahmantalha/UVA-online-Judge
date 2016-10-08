#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    long long n,x;
    int i;
    while(scanf("%lld",&n)==1)
    {
        x=1;
        for(i=1;;i++)
        {
            x<<=1;
            if(x>n)
            break;
        }
        printf("%d\n",i);
    }
    return 0;
}
