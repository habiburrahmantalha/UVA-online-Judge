
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

int d[20],n;
string str;

bool div(int x)
{
    int rem=0,len,i;

    for(i=0;i<str.size();i++)
        rem=(rem*10+(str[i]-'0'))%x;

    if(rem==0)
    return true;
    else
    return false;
}
bool divisible()
{
    for(int i=0;i<n;i++)
    if(!div(d[i]))
    return false;

    return true;
}
int main()
{
    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&d[i]);
        if(divisible())
            printf("%s - Wonderful.\n",str.c_str());
        else
            printf("%s - Simple.\n",str.c_str());

    }
    return 0;
}



