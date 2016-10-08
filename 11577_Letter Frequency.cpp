#include<stdio.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;

string str;
map<char,int> mp;

void frequency()
{
    int i,j;
    char ch;
    map<char,int> ::iterator it;

    for(i=0;i<str.size();i++)
        if(isalpha(str[i]))
            mp[tolower(str[i])]++;

    int max=0;
    for(it=mp.begin();it!=mp.end();it++)
        if(max<(*it).second)
        max=(*it).second;
    for(it=mp.begin();it!=mp.end();it++)
        if(max==(*it).second)
            cout<<(*it).first;
        cout<<endl;

}
int main()
{


    int tc;
    char ch;
    scanf("%d\n",&tc);

    while(tc--)
    {
        getline(cin,str);
        frequency();
        mp.clear();
    }
    return 0;
}
