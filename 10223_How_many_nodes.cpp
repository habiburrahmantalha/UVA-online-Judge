#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

double c[40];
map<long long,int>mp;
void precal()
{
    c[0]=1;
    for(int i=0;i<25;i++)
    {
        c[i+1]=(((4*i)+2)*c[i])/(i+2);
        mp[(long long)c[i+1]]=i+1;
    }
}
int main()
{
    precal();
    long long n;
    while(scanf("%lld",&n)==1)
    {
        printf("%d\n",mp[n]);
    }
    return 0;
}
