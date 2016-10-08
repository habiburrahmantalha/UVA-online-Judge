//Problem Type :
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
    long long x,t,i,p;
    bool f;
    while(scanf("%lld",&x)==1)
    {
        p=1;
        f=false;
        while(p<x)
        {
           if(!f)
           {
               if(p*9>=x)
               {
                   f=true;
                   break;
               }
               else
               {
                   p*=2;
                   f=true;
               }
           }
           else
           {
               p*=9;
               f=false;
               if(p>=x)
                   break;

           }
           //cout<<p<<" ";
        }
        if(f)
        printf("Stan wins.\n");
        else
        printf("Ollie wins.\n");

    }
    return 0;
}
