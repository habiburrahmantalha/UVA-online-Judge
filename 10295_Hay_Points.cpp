#include<stdio.h>
#include<string>
#include<string.h>
#include<map>
#include<iostream>
using namespace std;

int main()
{
    string str;
    int m,n,i,count,point;
    map<string,int> mp ;
    while(scanf("%d %d",&m,&n)==2)
    {
        for(i=0;i<m;i++)
        {
            cin>>str>>point;
            mp[str]=point;
        }
        for(i=0;i<n;i++)
        {
            count=0;
            while(1)
            {
                cin>>str;
                if(str==".")
                    break;
                count+=mp[str];
            }
            printf("%d\n",count);
        }
    }
    return 0;
}
