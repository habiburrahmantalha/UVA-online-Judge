#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    string s1,s2,s;
    int i,m;
    map<char,int> mp1,mp2;
    map<char,int> :: iterator it;
    while(getline(cin,s1))
    {
        getline(cin,s2);
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        if(s1.size()>s2.size())
        {
            s=s1;
            s1=s2;
            s2=s;
        }
        for(i=0;i<s1.size();i++)
            mp1[s1[i]]++;

        for(i=0;i<s2.size();i++)
            mp2[s2[i]]++;

        for(it=mp1.begin();it!=mp1.end();it++)
            if(it->second>0 && mp2[it->first]>0)
            {
                m=min(it->second,mp2[it->first]);
                while(m--)
                {
                    cout<<it->first;
                }
            }
        cout<<endl;
        mp1.clear();
        mp2.clear();

    }
    return 0;
}
