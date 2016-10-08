#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

map<char,int>mp;


string str;
long long p[35];
void power()
{
    p[0]=0;
    p[1]=4;
    for(int i=2;i<=30;i++)
    p[i]=p[i-1]*4;
}
long long DNA(int i)
{
    if(i==str.size()-1)
    return mp[str[i]];
    return p[str.size()-i-1]*mp[str[i]]+DNA(i+1);
}
int main()
{
    power();
    mp['A']=0;
    mp['C']=1;
    mp['G']=2;
    mp['T']=3;
    int tc,t=1;
    long long res;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;
        long long res=DNA(0);
        printf("Case %d: (%d:%lld)\n",t++,str.size(),res);
    }
    return 0;
}
