#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
#include<algorithm>
#include<ctype.h>
#include<vector>
using namespace std;

string str;
vector<string>v;
map<char,int>mp;

bool valid(int i)
{
    int j,k;
    for(j=0;j<v[i].size();j++)
    {
        if(mp[v[i][j]]==0)
        {
            for(k=0;k<j;k++)
            mp[v[i][k]]++;
            return false;
        }
        else
        {
            mp[v[i][j]]--;
        }
    }
    for(k=0;k<v[i].size();k++)
    mp[v[i][k]]++;
    return true;
}


int main()
{
    char ch;
    int c;
    while(cin>>str)
    {

        v.push_back(str);
        while(cin>>str)
        {
            if(str[0]=='#')
            break;
            v.push_back(str);
        }

        while((ch=getchar())!='#')
        {
            if(isalpha(ch))
            mp[ch]++;
            while((ch=getchar())!='\n')
            {
                if(isalpha(ch))
                mp[ch]++;
            }
            c=0;
            for(int i=0;i<v.size();i++)
            {
                if(valid(i))
                c++;
            }
            printf("%d\n",c);
            mp.clear();
        }
        v.clear();
    }
    return 0;
}
