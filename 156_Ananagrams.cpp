#include<stdio.h>
#include<string>
#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
#include<ctype.h>
using namespace std;

int main()
{
    int i;
    string str,temp;
    map<string,vector<string> > mv;
    map<string,vector<string> > :: iterator it;
    vector<string> v;

    while(cin>>str && str!="#")
    {
        temp="";
        for(i=0;i<str.size();i++)
            temp+=tolower(str[i]);
        sort(temp.begin(),temp.end());

        mv[temp].push_back(str);
    }
    for(it=mv.begin();it!=mv.end();it++)
    {
        if(it->second.size()==1)
            v.push_back(it->second[0]);
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++)
        cout<<v[i]<<endl;

    return 0;

}
