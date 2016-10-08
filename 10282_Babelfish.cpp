#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>
using namespace std;

int main()
{
    map<string,string> mp;
    char s1[20],s2[20],s[50];

    while(gets(s))
    {
        if(strlen(s)==0)
            break;
        sscanf(s,"%s %s",s1,s2);
        mp[s2]=s1;

    }
    while(scanf("%s",s1)==1)
    {
        if(mp[s1]=="")
            printf("eh\n");
        else
            printf("%s\n",mp[s1].c_str());
    }
    return 0;
}
