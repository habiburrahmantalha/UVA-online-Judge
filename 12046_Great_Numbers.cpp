#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

bool great_number(int x)
{
    int y,d;
    y=x;
    while(y)
    {
        d=y%10;
        if(d>6)
        return false;
        if(!d || x%d!=0)
        return false;

        y/=10;
    }
    return true;
}
void precal()
{
    int i,c=0;
    for(i=100;i<=999;i++)
    {
        if(great_number(i))
        {
            printf("%d\n",i);
            c=(c+1)%1000007;
        }
    }
    printf("%d\n",c);
}

int main()
{
    precal();
    return 0;
}
