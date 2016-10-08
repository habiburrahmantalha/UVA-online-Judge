#include<string>
#include<stdio.h>
#include<map>
#include<iostream>
using namespace std;


int main()
{
    string str,temp,res;
    map<string,int> mp;
    map<string,int> :: iterator it;
    int n,i,max;
    while(cin>>n>>str)
    {
        for(i=0;i<=str.size()-n;i++)
        {
            temp=str.substr(i,n);
            //cout<<temp<<endl;
            mp[temp]++;
        }
        max=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second>max)
            {
                max=it->second;
                res=it->first;
            }
        }
        cout<<res<<endl;
        mp.clear();
    }
    return 0;
}
