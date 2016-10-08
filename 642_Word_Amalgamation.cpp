#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    string str,str2;
    int size,i;
    map<string,vector<string> > mv;
    while(cin>>str)
    {
        if(str=="XXXXXX")
            break;
        str2=str;
        sort(str2.begin(),str2.end());
        mv[str2].push_back(str);
    }
    while(cin>>str)
    {
        if(str=="XXXXXX")
            break;
        sort(str.begin(),str.end());
        size=mv[str].size();
        if(size==0)
            printf("NOT A VALID WORD\n");
        else
        {
            sort(mv[str].begin(),mv[str].end());
            for(i=0;i<size;i++)
                printf("%s\n",mv[str][i].c_str());
        }
            printf("******\n");
    }
    return 0;
}
