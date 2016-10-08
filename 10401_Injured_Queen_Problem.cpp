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

bool valid(int i,int j)
{
    if(i-1>=0 && i+1<l)
    {
        if(s[j+1]=='?')
            return true;
        else
        {
            if(s[j+1]-'0'==i || s[j+1]-'0'==i+1 || s[j+1]-'0'==i-1)
            return false;
        }
    }
    return true;
}
void table()
{
    if(s[0]=='?')
    {
        if(valid(0,s[0]-'0'))
            T[0][s[0]-'0']=1;
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(valid(0,i))
                T[0][i]=1;
        }
    }

    for(i=1;i<n;i++)
    {

    }
}

int main()
{
    while(scanf("%d",&s+1)==1)
    {
        table();
    }
    return 0;
}
