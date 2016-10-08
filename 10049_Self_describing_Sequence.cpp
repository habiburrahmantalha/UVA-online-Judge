#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

long long T[2000000];
void precal()
{
    long long a=1,in=2,i;
    T[1]=1;
    while(in<2000000)
    {
        for(i=0;i<a;i++,in++)
        T[in]=T[in-1]+a;
        a++;

    }
    //for(i=0;i<1000001;i++)
    printf("%lld %lld\n",i,T[2000000]);

}
int main()
{
    precal();
    return 0;
}
