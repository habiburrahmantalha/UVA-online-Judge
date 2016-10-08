#include<string>
#include<list>
#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

string str;
set<string> dictionary;
set<string>::iterator it;

void lower_erase()
{
    int i;
    string word="";
    for(i=0;i<str.size();i++)
    {
        if(isalpha(str[i]))
                word+=tolower(str[i]);
        else
        {
            if(word.size()>0)
            {
                dictionary.insert(word);
                word="";
            }
        }

    }
}

int main()
{
    //freopen("in.txt","r",stdin);

    while(getline(cin,str))
    {
        str+=" ";
        lower_erase();
        //dictionary.insert(str);
    }
    for(it=dictionary.begin();it!=dictionary.end();it++)
        cout<<*it<<endl;
    return 0;
}
