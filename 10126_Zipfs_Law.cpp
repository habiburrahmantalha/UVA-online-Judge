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
#include<sstream>
using namespace std;
#define PI 2 * acos (0.0)


int main()
{
    int n,i;
    char s[100];
    string str;
    bool line=false;
    map<string,int> mp;
    while(scanf("%d",&n)==1)
    {
        if(line)
        printf("\n");
        line=true;

        while(cin>>str && str!="EndOfText")
        {
            for(i=0;i<str.size();i++)
            {
                if(isalpha(str[i]))
                str[i]=tolower(str[i]);
                else
                str[i]=' ';
            }
            stringstream ss(str);
            while(ss>>s)
            mp[s]++;
        }
        map<string,int> :: iterator it;
        bool f=false;
        for(it=mp.begin();it!=mp.end();it++)
        {
            if(it->second==n)
            {
                cout<<it->first<<endl;
                f=true;
            }
        }
        if(!f)
        cout<<"There is no such word."<<endl;
        mp.clear();

    }
    return 0;
}
