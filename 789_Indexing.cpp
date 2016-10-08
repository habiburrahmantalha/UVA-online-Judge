#include<stdio.h>
#include<string>
#include<map>
#include<set>
#include<algorithm>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    string key,str,temp;
    stringstream ss;
    int line=0,i;
    map<string,set<int> > mv;
    map<string,set<int> > :: iterator it;
    set<int> :: iterator its;
    getline(cin,key);
    while(getline(cin,str))
    {
        for(i=0;i<str.size();i++)
            if(!isalpha(str[i]))
            str[i]=' ';
        line++;
        ss<<str;

        while(ss>>str)
        {
            if(str[0]==key[0] )
            {

                mv[str].insert(line);


            }
        }

        ss.clear();
    }
     for(it=mv.begin();it!=mv.end();it++)
        {
            cout<<it->first<<" ";
            for(its=it->second.begin();;)
            {
                cout<<*its;
                break;
            }
            for(its++;its!=it->second.end();its++)
            {
                cout<<" "<<*its;

            }
            cout<<endl;
        }
    return 0;
}
