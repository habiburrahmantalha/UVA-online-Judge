//X( hate this problem setter.
#include<string>
#include<list>
#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;

string str;

void lower_erase()
{
    int i;
    for(i=0;i<str.size();i++)
    {
        if(isalpha(str[i]))
        {
            if(isupper(str[i]))
                str[i]=tolower(str[i]);
        }
        else if(str[i]=='-')
            continue;
        else
        {
            str.erase(i,1);
            i--;
        }
    }
    if(str[str.size()-1]=='-')
        str.erase(str.size()-1,1);
}

int main()
{
    freopen("in.txt","r",stdin);
    list<string> dictionary;
    list<string>::iterator it;
    char ch;
    string str2;

    while(cin>>str)
    {
        ch=getchar();
        //if(str[str.size()-1]=='-' && ch=='\n')
        while(str[str.size()-1]=='-' && (ch=='\n'|| ch==' '))
        {
            cin>>str2;
            str.erase(str.size()-1,1);
            str+=str2;
        }

        lower_erase();
        dictionary.push_back(str);
        dictionary.sort();
        dictionary.unique();

    }
    for(it=dictionary.begin();it!=dictionary.end();it++)
        cout<<*it<<endl;
    return 0;
}
