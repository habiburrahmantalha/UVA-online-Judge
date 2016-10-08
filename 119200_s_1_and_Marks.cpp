//:P
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;



int count(string x)
{
    for(i=0;i<x.size();i++)
    {
        if(x[i]=='?')
        {

        }
        else
        y[in++]=s[i];
    }
}

int main()
{
    int k,tc;
    string str;
    scanf("%d",&tc);

    for(k=1;k<=tc;k++)
    {
        cin>>str;
        printf("Case %d: %d\n",count(str));
    }
    return 0;
}
