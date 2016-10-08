#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int T[10000];
void precal()
{
    int a=1,in=2,i;
    T[1]=1;
    while(in<1000)
    {
        for(i=0;i<a;i++,in++)
        T[in]=T[in-1]+a;
        a++;

    }
    for(i=0;i<101;i++)
    printf("%d %d\n",i,T[i]);

}
int main()
{
    precal();
    return 0;
}
