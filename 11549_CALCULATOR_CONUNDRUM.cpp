//Problem Type :    cycle finding
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

long long mx,n,k;
map<long long,bool>m;
long long first_n()
{
    char a[30];
    sprintf(a,"%lld",k);
    a[n]=0;
    return atol(a);
}
void cycle_find()
{
    mx=k;
    while(!m[k])
    {
        m[k]=true;
        k*=k;
        k=first_n();
        mx=max(mx,k);



    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        m.clear();
        scanf("%lld %lld",&n,&k);
        cycle_find();
        printf("%lld\n",mx);

    }
    return 0;
}
