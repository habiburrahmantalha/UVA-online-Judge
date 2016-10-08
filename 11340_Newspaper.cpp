#include<map>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include<string>
#define LL long long
using namespace std;

int main()
{

    map<char,LL>mp;
    LL tc,i,j,k,sum,v,len;
    double res;
    char ch;

    scanf("%lld",&tc);
    while(tc--)
    {
        scanf("%lld\n",&k);

        for(i=0;i<k;i++)
        {
            cin>>ch>>v;
            mp[ch]=v;
        }
        scanf("%lld",&k);
        getchar();
        sum=0;

        for(i=0;i<k;i++)
        {
            while(1)
            {
                ch=getchar();
                if(ch==10)
                    break;
                sum+=mp[ch];
            }
        }
        res=double(sum);
        printf("%.2lf$\n",res/100);
        mp.clear();
    }
    return 0;
}
