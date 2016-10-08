#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

long long a[200010];
char str[1000010];
void precal()
{
    a[0]=0;
    a[1]=0;
    a[2]=1;
    a[3]=2;
    for(int i=2;i<100000;i++)
    {
        a[i*2]=a[i*2-1]=a[i]+1;
    }
}

bool space()
{
    int l,i,mx,c;
    l=strlen(str);
    mx=c=0;
    for(i=0;i<l;i++)
    if(str[i]==' ')
        c++;
    else
    {
        if(mx<c)
        mx=c;
        c=0;
    }
    //printf("%d ",mx);
    printf("%lld\n",a[mx]);
}
int main()
{
    precal();
    while(gets(str))
    {
        space();
    }
    return 0;
}
